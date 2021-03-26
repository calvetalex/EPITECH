#!/bin/env python3

from sys import argv as av, stderr
import re
from collections import Counter
from itertools import count, cycle


def hamming_distance(bytes1, bytes2):
    distance = ' '.join(f"{i ^ j:08b}" for i, j in zip(bytes1, bytes2))

    return distance.count('1')


def get_english_score(string):
    letter_freq = [0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02,
                   0.061, 0.07, 0.0015, 0.0077, 0.04, 0.024,
                   0.067, 0.075, 0.019, 0.00095, 0.06, 0.063,
                   0.091, 0.028, 0.0098, 0.024, 0.0015, 0.02,
                   0.00074]
    space_freq = 0.13

    counter = Counter(string.lower())

    return sum(counter.get(chr(c + ord('a')), 0) * letter_freq[c]
               for c in range(26)) + counter.get(' ', 0) * space_freq


def single_byte_xor(hex_string, key_byte):
    return bytes(b ^ key_byte for b in hex_string)


def brute_force_single_byte_xor(hex_string):
    deciphered_texts = []

    for key in range(1, 256):
        try:
            msg = bytes(single_byte_xor(hex_string, key))
            score = get_english_score(msg.decode())
            data = {"msg": msg, "score": score, "key": key}

            deciphered_texts.append(data)
        except UnicodeError:
            continue

    deciphered_texts.sort(key=lambda x: x["score"], reverse=True)

    return deciphered_texts[0]


def repeat_key_xor(hex_string, hex_key):
    return bytes(k ^ i for k, i in zip(cycle(hex_key), hex_string))


def break_repeat_key_xor(string):
    hex_string = bytes.fromhex(string)

    average_distances = []
    for keysize in range(5, 41):
        chunks = [hex_string[i:i + keysize]
                  for i in range(0, len(hex_string), keysize)]
        distances = []

        while len(chunks) >= 2:
            chunk1 = chunks[0]
            chunk2 = chunks[1]

            distance = hamming_distance(chunk1, chunk2)

            distances.append(distance / keysize)

            del chunks[0]
            del chunks[0]

        result = {"key": keysize, "avg_distance": sum(
            distances) / len(distances)}
        average_distances.append(result)

    average_distances.sort(key=lambda x: x["avg_distance"])

    possible_key_lengths = [x["key"] for x in average_distances[:3]]
    # sort to get the smallest key length first, as the bigger ones
    # might simply be the smallest one repeated several times
    possible_key_lengths.sort()
    possible_plaintexts = []

    for key_length in possible_key_lengths:
        chunks = [hex_string[i:i + key_length]
                  for i in range(0, len(hex_string), key_length)]
        transposed = [b''.join(c[i:i + 1] for c in chunks)
                      for i in range(key_length)]
        key = bytes(brute_force_single_byte_xor(c)["key"] for c in transposed)
        possible_plaintexts.append((repeat_key_xor(hex_string, key), key))

    plaintext = max(possible_plaintexts, key=lambda x: get_english_score(x[0]))

    print(''.join(f"{x:X}" for x in plaintext[1]))


def main(argc, argv):
    if argc != 2:
        print(f"Pass a filepath as argument", file=stderr)
        return 84

    filepath = argv[1]
    try:
        file = open(filepath)
    except OSError:
        print(f"Could not open {filepath}", file=stderr)
        return 84

    with file:
        content = file.read()

        regex = r"^([0-9A-F]+)\n?$"

        match = re.match(regex, content)
        if match:
            break_repeat_key_xor(match.group(1))
        else:
            print(f"Invalid file content", file=stderr)
            return 84

    return 0


if __name__ == "__main__":
    exit(main(len(av), av))
