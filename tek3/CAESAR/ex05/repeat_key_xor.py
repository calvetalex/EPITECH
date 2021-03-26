#!/bin/env python3

from sys import argv as av, stderr
import re
from itertools import cycle


def repeat_key_xor(key, string):
    hex_key = bytes.fromhex(key)
    hex_string = bytes.fromhex(string)

    xor_value = bytes(k ^ i for k, i in zip(cycle(hex_key), hex_string))

    for x in xor_value:
        print(f"{x:X}", end='')
    print()


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

        regex = r"^([0-9A-F]+)\n([0-9A-F]+)\n?$"

        match = re.match(regex, content)
        if match:
            repeat_key_xor(match.group(1), match.group(2))
        else:
            print(f"Invalid file content", file=stderr)
            return 84

    return 0


if __name__ == "__main__":
    exit(main(len(av), av))
