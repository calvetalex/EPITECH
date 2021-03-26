#!/usr/bin/env python3

import sys
import os
import re
from collections import Counter

def single_byte_xor(string, idx):
    hex_value = bytes.fromhex(string)
    tests = [bytes((key + 1) ^ i for i in hex_value)
             for key in range(127)]
    # common_letters = {'e': 0.13, 't': 0.091, 'a': 0.082, 'i': 0.07,
    #                   'o': 0.075, 'n': 0.067, 's': 0.063,
    #                   'h': 0.061, 'r': 0.06, 'd': 0.043,
    #                   'l': 0.04, 'u': 0.028}
    common_letters = {
        'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253,
        'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
        'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025,
        'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
        'q': .00095, 'r': .05987, 's': .06327, 't': .09056,
        'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
        'y': .01974, 'z': .00074, ' ': .13000
    }
    counts = []

    for i, t in enumerate(tests, start=1):
        try:
            s = t.decode()
        except UnicodeError:
            continue
        counter = Counter(s)
        average = sum(counter.get(c, 0) * common_letters[c]
                      for c in common_letters.keys())
        counts.append((i, s, average))
    counts.sort(key=lambda c: c[2], reverse=True)
    if len(counts) > 0:
        return counts[0]
    return [0, '', 0]

def main(filename):
    try:
        with open(filename, 'r') as f:
            encryptedLines = list(filter(lambda x: len(x) > 0, [(line[:-1] if line[-1] == '\n' else line) for line in f]))
    except IndexError:
        print("an error occured when getting file informations...", file=sys.stderr)
        return 84
    except ValueError:
        print("an error occured when getting file informations...", file=sys.stderr)
        return 84
    regex = r"^([0-9A-F]+)\n?$"
    potential = []
    for idx, content in enumerate(encryptedLines):
        match = re.match(regex, content)
        if match:
            value = single_byte_xor(match.group(1), idx)
            potential.append({
                "line": idx,
                "key": value[0],
                "content": value[1],
                "score": value[2]
            })
        else:
            print(f"Invalid file content", file=stderr)
            return 84
    potential.sort(key=lambda  c: c["score"], reverse=True)
    print(f'{potential[0]["line"]} {potential[0]["key"]:X}')
    return 0
 
if __name__=="__main__":
    if len(sys.argv) != 2:
        print("ERROR: filename expected", file=sys.stderr)
        exit(84)
    try:
        if os.stat(sys.argv[1]).st_size == 0:
            print("ERROR: empty file", file=sys.stderr)
            exit(84)
    except OSError:
        print("ERROR: can t find file given in arg", file=sys.stderr)
        exit(84)
    exit(main(sys.argv[1]))