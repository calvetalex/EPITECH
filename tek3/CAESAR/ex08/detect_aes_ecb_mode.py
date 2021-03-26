#!/bin/env python3

from sys import argv as av, stderr
import os
import base64
from collections import Counter


def detect_aes_ecb_mode(b64_lines):
    try:
        hex_lines = [base64.b64decode(line) for line in b64_lines]
    except:
        print("Invalid file content", file=stderr)
        return 84

    freq = []
    for i, line in enumerate(hex_lines, start=1):
        c = Counter(line).most_common(4)
        s = sum(t[1] for t in c)
        freq.append((i, s))

    i, _ = max(freq, key=lambda t: t[1])

    print(i)
    # print(' '.join(f"{i:X}" for i in hex_lines[14]))
    # print(' '.join(f"({v:X}, {c})" for v, c in Counter(
    #     hex_lines[14]).most_common(4)))


def main(argc, argv):
    if argc != 2:
        print(f"Pass a filepath as argument", file=stderr)
        return 84

    filepath = argv[1]
    try:
        if os.stat(filepath).st_size == 0:
            print("ERROR: empty file", file=stderr)
            return 84
        file = open(filepath)
    except OSError:
        print(f"Could not open {filepath}", file=stderr)
        return 84

    with file:
        return detect_aes_ecb_mode(file.readlines())

    return 0


if __name__ == "__main__":
    exit(main(len(av), av))
