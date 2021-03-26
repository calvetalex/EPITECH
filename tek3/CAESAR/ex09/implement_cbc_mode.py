#!/bin/env python3

from sys import argv as av, stderr
import re
import base64
from Crypto.Cipher import AES


def unpad_pkcs7(ct):
    return ct[:-ct[-1]]


def xor_2_byte_strings(bytes1, bytes2):
    return bytes(a ^ b for a, b in zip(bytes1, bytes2))


def implement_cbc_mode(key, iv, b64_ciphertext):
    hex_key = bytes.fromhex(key)
    hex_iv = bytes.fromhex(iv)
    try:
        hex_ciphertext = base64.b64decode(b64_ciphertext)
    except:
        print("Invalid file content", file=stderr)
        return 84

    obj = AES.new(hex_key, AES.MODE_ECB)
    blocks = [hex_iv] + [hex_ciphertext[i:i + 16]
                         for i in range(0, len(hex_ciphertext), 16)]
    hex_plaintext = []
    for i in range(1, len(blocks)):
        xor_plaintext = obj.decrypt(blocks[i])
        hex_plaintext.append(xor_2_byte_strings(xor_plaintext, blocks[i - 1]))
    hex_plaintext = b''.join(hex_plaintext)
    hex_plaintext = unpad_pkcs7(hex_plaintext)

    print(base64.b64encode(hex_plaintext).decode())


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

        regex = r"^([0-9A-F]+)\n([0-9A-F]+)\n(.+)\n?$"

        match = re.match(regex, content)
        if match:
            return implement_cbc_mode(*match.groups())
        else:
            print(f"Invalid file content", file=stderr)
            return 84

    return 0


if __name__ == "__main__":
    exit(main(len(av), av))
