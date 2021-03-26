#!/bin/env python3

import sys
from ai import AI, CellState

MIN_SIZE = 5
MAX_SIZE = 100
ABOUT = '''name="Off-IceAI", version="1.0.1", author="off-ice.algo.team", country="France"'''
FIRST_TURN = True

ai_instance = None


def send(message=""):
    print(message, flush=True)


def debug_cmd(message=""):
    send(f"DEBUG {message}")


def error_cmd(message=""):
    send(f"ERROR {message}")


def start_cmd(size):
    global MIN_SIZE, MAX_SIZE, ai_instance
    size = int(size)
    if size < MIN_SIZE or size > MAX_SIZE:
        error_cmd(
            f"Given size is {size} but it must be between {MIN_SIZE} and {MAX_SIZE}")
        sys.exit(84)
    ai_instance = AI(size, strategy="weighted")
    send("OK")


def restart_cmd():
    if ai_instance:
        ai_instance.reset()
    send("OK")


def turn_cmd(x, y):
    x, y = int(x), int(y)
    if not ai_instance:
        return
    ai_instance.set_value(x, y, CellState.ENEMY)
    x, y = ai_instance.get_next_move()
    debug_cmd(
        f"AI wants to play here {x, y}: isValid ? {ai_instance.is_valid_move(x, y)}")
    ai_instance.set_value(x, y, CellState.AI)
    send(f"{x},{y}")


def begin_cmd():
    global FIRST_TURN

    FIRST_TURN = False
    if ai_instance:
        x, y = ai_instance.first_move()
        ai_instance.set_value(x, y, CellState.AI)
        send(f"{x},{y}")


def board_cmd():
    if not ai_instance:
        return
    for line in sys.stdin:
        if line.startswith("DONE"):
            break
        pos = line.strip().split(",")
        x, y, player = int(pos[0]), int(pos[1]), CellState.from_char(pos[2])
        ai_instance.set_value(x, y, player)
    x, y = ai_instance.get_next_move()
    ai_instance.set_value(x, y, CellState.AI)
    send(f"{x},{y}")


def info_cmd(_=None, __=None):
    pass


def end_cmd():
    sys.exit(0)


def about_cmd():
    global ABOUT
    send(ABOUT)


def main():
    switch = {
        "START":  start_cmd,
        "TURN":  turn_cmd,
        "BEGIN":  begin_cmd,
        "BOARD":  board_cmd,
        "INFO":  info_cmd,
        "END":  end_cmd,
        "ABOUT":  about_cmd,
        "RESTART": restart_cmd,
    }

    for line in sys.stdin:
        args = line.strip().replace(",", " ").split(" ")
        if args[0] in switch:
            try:
                switch[args[0]](*args[1:])
            except Exception as e:
                send(f"ERROR could not execute {' '.join(args)}")
        else:
            send(f"UNKNOWN cannot found command {args[0]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
