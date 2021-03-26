#!/bin/env python3

import argparse
from sys import stderr
from guimoku import Board


def check_arg(arg):
    try:
        arg = int(arg)
        if arg < 1:
            raise ValueError
    except ValueError:
        raise argparse.ArgumentTypeError("must be an positive integer")
    return arg


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Play a Gomoku game (Tic Tac Toe)")
    parser.add_argument("-v", "--verbose", action="store_true",
                        help="display the parameter values (default: disabled)")
    parser.add_argument("-n", "--size", type=int, default=5,
                        help="size of the board (default: 5)")
    parser.add_argument("-c", "--cell_size", type=int, default=80,
                        help="size of a cell (in px)  (default: 80)")
    parser.add_argument("-l", "--line_thickness", type=int, default=10,
                        help="thickness of lines (in px)  (default: 10)")
    parser.add_argument("-w", "--win_length", type=int, default=5,
                        help="number of cell in a row to fill to win (default: 5)")
    parser.add_argument("-s", "--start-circle", action="store_true",
                        help="first player is Circle (default: Cross)")
    parser.add_argument("--cross", default=None,
                        help="path to the AI executable for the cross player (default: human player)")
    parser.add_argument("--circle", default=None,
                        help="path to the AI executable for the circle player (default: human player)")
    args = parser.parse_args()

    if args.verbose:
        print("n = {}, cell_size = {}, line_thickness = {}, win_length = {}, starting player = {}".format(
            args.size, args.cell_size, args.line_thickness, args.win_length, "Circle" if args.circle else "Cross"))
    if args.size < args.win_length:
        print(
            f"SIZE ({args.size}) cannot be less than WIN_LENGTH ({args.win_length})", file=stderr)
        exit(1)

    guimoku = Board(n=args.size, cell_size=args.cell_size, line_thickness=args.line_thickness,
                    win_length=args.win_length, start_player=args.circle, cross=args.cross, circle=args.circle)
    guimoku.run()
