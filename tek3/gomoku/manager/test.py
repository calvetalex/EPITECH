#!/bin/env python3

import random

while True:
    s = input()  # get input from stdin
    i = random.randint(0, len(s))  # process the input
    print("line 2", flush=True)
    print(f"New output {i}", flush=True)  # prints processed input to stdout
