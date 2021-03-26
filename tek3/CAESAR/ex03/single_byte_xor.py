#!/bin/env python3

from sys import argv as av, stderr
import re
from collections import Counter


def single_byte_xor(string):
    hex_value = bytes.fromhex(string)

    tests = [bytes((key + 1) ^ i for i in hex_value)
             for key in range(127)]

    common_letters = {'e': 0.13, 't': 0.091, 'a': 0.082, 'i': 0.07,
                      'o': 0.075, 'n': 0.067, 's': 0.063,
                      'h': 0.061, 'r': 0.06, 'd': 0.043,
                      'l': 0.04, 'u': 0.028}

    counts = []
    for i, t in enumerate(tests, start=1):
        s = t.decode().casefold()

        if not s.isprintable():
            continue

        counter = Counter(s)
        average = sum(counter.get(c, 0) * common_letters[c]
                      for c in common_letters.keys())

        counts.append((i, s, average))

    counts.sort(key=lambda c: c[2], reverse=True)

    return counts


def main(argc, argv):
    if argc < 2:
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
            counts = single_byte_xor(match.group(1))
            print(f"{counts[0][0]:X}")
        else:
            print(f"Invalid file content", file=stderr)
            return 84

    return 0


if __name__ == "__main__":
    exit(main(len(av), av))
