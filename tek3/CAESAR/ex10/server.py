#!/usr/bin/env python3
"""
Very simple HTTP server in python for logging requests
Usage::
    ./server.py [<port>]
"""
from http.server import BaseHTTPRequestHandler, HTTPServer
import base64
from Crypto.Cipher import AES

APPENDED_STRING = b"CURVE"


def pad_pkcs7(m):
    complement = 16 - len(m) % 16
    return m + str.encode(chr(complement) * complement)


class S(BaseHTTPRequestHandler):
    def _set_response(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        print("GET request,\nPath: %s\nHeaders:\n%s",
              str(self.path), str(self.headers))
        self._set_response()
        self.wfile.write("GET request for {}".format(
            self.path).encode('utf-8'))

    def do_POST(self):
        # <--- Gets the size of data
        content_length = int(self.headers['Content-Length'])
        # <--- Gets the data itself
        post_data = self.rfile.read(content_length)
        print("POST request,\nPath: %s\nHeaders:\n%s\nBody:\n%s" %
              (str(self.path), str(self.headers), post_data.decode('utf-8')))

        hex_plaintext = base64.b64decode(post_data)
        hex_key = b"--CRYPTOGRAPHY--"
        obj = AES.new(hex_key, AES.MODE_ECB)
        hex_ciphertext = obj.encrypt(
            pad_pkcs7(hex_plaintext + APPENDED_STRING))
        response_data = base64.b64encode(hex_ciphertext)

        self._set_response()
        self.wfile.write(response_data)


def run(server_class=HTTPServer, handler_class=S, port=5000):
    addr = '127.0.0.1'
    httpd = server_class((addr, port), handler_class)
    print('Starting httpd...')
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    print('Stopping httpd...')


if __name__ == '__main__':
    run()
