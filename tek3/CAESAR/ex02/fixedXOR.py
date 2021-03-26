#!/usr/bin/env python3

import sys
import os
import re

def main(filename):
    try:
        if os.stat(filename).st_size == 0:
            print("ERROR: file is empty", file=sys.stderr)
            return(84)
    except OSError:
        print("ERROR: file not found", file=sys.stderr)
        return 84
    with open(filename, 'r') as f:
        nb1 = f.readline().rstrip('\n\r').upper()
        nb2 = f.readline().rstrip('\n\r').upper()
    if len(nb1) != len(nb2):
        print("ERROR: length must be identical for each numbers", file=sys.stderr)
        return 84
    regex = r"^([0-9A-F]{2})"
    if not re.match(regex, nb1) or not re.match(regex, nb2):
        print("ERROR: not hex data", file=sys.stderr)
        return 84
    xor = hex(int(nb1, base=16) ^ int(nb2, base=16))
    print(xor.upper().lstrip("0X"))
    return 0


if __name__=="__main__":
    if len(sys.argv) != 2:
        print("ERROR: file name expected", file=sys.stderr)
        exit(84)
    exit(main(sys.argv[1]))