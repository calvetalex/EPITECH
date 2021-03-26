#!/bin/env python3

from sys import argv as av, stderr
import re
import base64
from Crypto.Cipher import AES


def pad_pkcs7(m):
    complement = 16 - len(m) % 16
    return m + chr(complement) * complement


def unpad_pkcs7(ct):
    return ct[:-ct[-1]]


def aes_ecb_mode(key, base64_msg):
    hex_key = bytes.fromhex(key)

    if len(hex_key) != 16:
        return 84

    try:
        ciphertext = base64.b64decode(base64_msg)
    except:
        print("Invalid file content", file=stderr)
        return 84

    obj = AES.new(hex_key, AES.MODE_ECB)

    try:
        hex_plaintext = obj.decrypt(ciphertext)
        hex_plaintext = unpad_pkcs7(hex_plaintext)
        b64_plaintext = base64.b64encode(hex_plaintext)
        print(b64_plaintext.decode())
    except:
        print("Invalid file content", file=stderr)
        return 84


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

        regex = r"^([0-9A-F]+)\n(.*)\n?$"

        match = re.match(regex, content)
        if match:
            return aes_ecb_mode(match.group(1), match.group(2))
        else:
            print(f"Invalid file content", file=stderr)
            return 84

    return 0


if __name__ == "__main__":
    exit(main(len(av), av))
