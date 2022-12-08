#!/usr/bin/env python3


from math import inf


patterns = [{'pattern': '11111', 'weight': inf},
            {'pattern': '01111', 'weight': 4},
            {'pattern': '10111', 'weight': 4},
            {'pattern': '11011', 'weight': 4},
            {'pattern': '11101', 'weight': 4},
            {'pattern': '11110', 'weight': 4},
            {'pattern': '11100', 'weight': 3},
            {'pattern': '11010', 'weight': 3},
            {'pattern': '10110', 'weight': 3},
            {'pattern': '00110', 'weight': 3},
            {'pattern': '11001', 'weight': 3},
            {'pattern': '10101', 'weight': 3},
            {'pattern': '01101', 'weight': 3},
            {'pattern': '10011', 'weight': 3},
            {'pattern': '01011', 'weight': 3},
            {'pattern': '00111', 'weight': 3},
            {'pattern': '11000', 'weight': 2},
            {'pattern': '10100', 'weight': 2},
            {'pattern': '10010', 'weight': 2},
            {'pattern': '10001', 'weight': 2},
            {'pattern': '01100', 'weight': 2},
            {'pattern': '01010', 'weight': 2},
            {'pattern': '01001', 'weight': 2},
            {'pattern': '00110', 'weight': 2},
            {'pattern': '00101', 'weight': 2},
            {'pattern': '00011', 'weight': 2},
            {'pattern': '10000', 'weight': 1},
            {'pattern': '01000', 'weight': 1},
            {'pattern': '00100', 'weight': 1},
            {'pattern': '00010', 'weight': 1},
            {'pattern': '00001', 'weight': 1},
            {'pattern': '20000', 'weight': -1},
            {'pattern': '02000', 'weight': -1},
            {'pattern': '00200', 'weight': -1},
            {'pattern': '00020', 'weight': -1},
            {'pattern': '00002', 'weight': -1},
            {'pattern': '22000', 'weight': -2},
            {'pattern': '20200', 'weight': -2},
            {'pattern': '20020', 'weight': -2},
            {'pattern': '20002', 'weight': -2},
            {'pattern': '02200', 'weight': -2},
            {'pattern': '02020', 'weight': -2},
            {'pattern': '02002', 'weight': -2},
            {'pattern': '00220', 'weight': -2},
            {'pattern': '00202', 'weight': -2},
            {'pattern': '00022', 'weight': -2},
            {'pattern': '22200', 'weight': -3},
            {'pattern': '22020', 'weight': -3},
            {'pattern': '20220', 'weight': -3},
            {'pattern': '02220', 'weight': -3},
            {'pattern': '22002', 'weight': -3},
            {'pattern': '20202', 'weight': -3},
            {'pattern': '02202', 'weight': -3},
            {'pattern': '20022', 'weight': -3},
            {'pattern': '02022', 'weight': -3},
            {'pattern': '00222', 'weight': -3},
            {'pattern': '02222', 'weight': -4},
            {'pattern': '20222', 'weight': -4},
            {'pattern': '22022', 'weight': -4},
            {'pattern': '22202', 'weight': -4},
            {'pattern': '22220', 'weight': -4},
            {'pattern': '22222', 'weight': -inf}]