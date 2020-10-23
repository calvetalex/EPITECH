#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import math
import re

def disp_h():
    print("USAGE:\n\t./109titration file\n")
    print("DESCRIPTION:\n\tfile\ta csv file containing \"vol;ph\" lines")

def derive_that(x0, x2, y0, y2):
    deriv = ((y2 - y0) / ( x2 - x0))
    return deriv

def maximum(res):
    i = 0
    while (res[i] < res[i+1]):
        i+= 1
    return i-1

def calcul(vol, ph):
    print("Derivative:")
    res = []
    for i in range(1, len(vol)-1):
        der = derive_that(float(vol[i-1]), float(vol[i+1]), float(ph[i-1]), float(ph[i+1]))
        res.append(der)
        print("{:.1f} ml -> {:.2f}".format(float(vol[i]), float(der)))
    maxi = maximum(vol)
    print("\nEquivalent point at {:.1f} ml".format(float(vol[maxi])))
    print("\nSecond derivative:")
    res2 = []
    for i in range(2, len(res)-1):
        print(res[i])
        result = derive_that(float(vol[i-1]), float(vol[i+1]), res[i-1], res[i+1])
        res2.append(result)
        print("{:.1f} ml -> {:.2f}".format(float(vol[i]), float(der)))

    return 0

def loop(file):
    with open(file, "r") as my_file:
        text = my_file.read()
        every = re.split(';|\n', text)
        vol, ph = [], []
        for i in range (0, len(every), 2):
            vol.append(every[i])
        for i in range (1, len(every), 2):
            ph.append(every[i])
        calcul(vol, ph)
    return 0

def main():
    if (len(sys.argv) != 2):
        exit(84)
    option = sys.argv[1]
    if (option == "-h"):
        disp_h()
        exit(0)
    else:
        file = sys.argv[1]
        ext = file[-4:]
        if (ext != ".csv"):
            exit(84)
        res = loop(file)
        if res == 0:
            exit(0)
        else:
            exit(84)
        exit(84)

main()