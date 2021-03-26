#!/bin/env python3

import requests
import base64

ADDR, PORT = "127.0.0.1", 5000


def oracle_encrypt(hex_body):
    r = requests.post(f"http://{ADDR}:{PORT}",
                      base64.b64encode(hex_body))

    return base64.b64decode(r.content)


def get_block_size():
    i = 1
    res = oracle_encrypt(b'A')
    res_len = len(res)
    new_len = res_len
    while res_len == new_len:
        res = oracle_encrypt(b'A' * i)
        new_len = len(res)
        i += 1
    res_len = new_len
    while res_len == new_len:
        res = oracle_encrypt(b'A' * i)
        new_len = len(res)
        i += 1
    block_size = new_len - res_len

    return block_size


def find_unknown_string_length():
    previous_length = len(oracle_encrypt(b''))
    i = 1
    while True:
        length = len(oracle_encrypt(b'X' * i))
        if length != previous_length:
            return previous_length - i
        i += 1


def get_next_byte(block_size, known_bytes):
    length = len(known_bytes)
    pad_length = - (length + 1) % block_size
    padding = b"A" * pad_length

    ii = len(known_bytes) // block_size
    target_slice = slice(ii * block_size, (ii + 1) * block_size)
    target_block = oracle_encrypt(padding)[target_slice]

    for i in range(256):
        appended_byte = bytes([i])
        msg = padding + known_bytes + appended_byte
        block = oracle_encrypt(msg)[target_slice]
        if block == target_block:
            return appended_byte


def main():
    try:
        block_size = get_block_size()
        unknown_string_length = find_unknown_string_length()
        known_bytes = b''

        for _ in range(unknown_string_length):
            known_bytes += get_next_byte(block_size, known_bytes)
        print(base64.b64encode(known_bytes).decode())

    except ConnectionError:
        return 84


if __name__ == "__main__":
    exit(main())
