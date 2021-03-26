#!/bin/env python3

from sys import argv as av, stderr
import re
import base64


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

        regex = r"^([0-9A-F]{2,})\n?$"

        match = re.match(regex, content)
        if match:
            hex_numbers = match.group(1)

            if len(hex_numbers) % 2 != 0:
                print(f"Invalid file content", file=stderr)
                return 84

            hex_value = bytes.fromhex(hex_numbers)
            base64_value = base64.b64encode(hex_value).decode()

            print(base64_value)
        else:
            print(f"Invalid file content", file=stderr)
            return 84

    return 0


if __name__ == "__main__":
    exit(main(len(av), av))
