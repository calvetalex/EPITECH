#!/usr/bin/env python3

import sys
import os
import base64

def getRepetition(line, blockSize):
    blocks = []
    for i in range(0, len(line), blockSize):
        blocks.append(line[i:i+blockSize])
    return len(blocks) - len(set(blocks))

def main(filename):
    blockSize = 16
    try:
        with open(filename, 'r') as f:
            datas = [base64.b64decode(line.rstrip('\n\r')) for line in f]
    except:
        print("ERROR: an error occured while parsing file informations", file=sys.stderr)
        return 84
    res = []
    for idx, data in enumerate(datas):
        res.append({
            'id': idx,
            'rep': getRepetition(data, blockSize),
            })
    res.sort(key=lambda c: c['rep'], reverse=True)
    print(res[0]['id'] + 1)
    return 0

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("ERROR: file expected", file=sys.stderr)
        exit(84)
    try:
        if os.stat(sys.argv[1]).st_size == 0:
            print("ERROR: empty file", file=sys.stderr)
            exit(84)
    except OSError:
        print("ERROR: can't open file", file=sys.stderr)
        exit(84)
    exit(main(sys.argv[1]))