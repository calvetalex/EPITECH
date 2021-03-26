#!/bin/python3

import sys
import time
from AI import AI
from CellState import CellState

MIN_SIZE = 5
MAX_SIZE = 100
ABOUT = '''name="Off-IceAI", version="1.0.1", author="off-ice.algo.team", country="France"'''
FIRST_TURN = True
DEBUG = False

ai: AI = None


def send(message=""):
    print(message, flush=True)


def aborting(message="ERROR message"):
    print(message, flush=True)
    sys.exit(84)


def startCmd(size, _):
    global MIN_SIZE, MAX_SIZE, ai
    size = int(size)
    if (size < MIN_SIZE or size > MAX_SIZE):
        aborting(
            f"ERROR message - Given size is {size} but must be greater or equal to {MIN_SIZE} and lower or equal to {MAX_SIZE}")
    ai = AI(size=size, strategy="weighted")
    send("OK")


def restartCmd(_, __):
    ai.reset()
    send("OK")


def turnCmd(x, y):
    global FIRST_TURN, DEBUG

    FIRST_TURN = False
    x, y = int(x), int(y)
    ai.set_value(x, y, CellState.ENEMY)
    if DEBUG == False:
        pos = ai.get_next_move()
        ai.set_value(pos[0], pos[1], CellState.AI)
    else:
        print("\nCurrent Board:")
        ai.debug()
        start = time.time()
        # pos = ai.getNextMove(-2, 2, True) # TODO: uncomment to use AlphaBeta class
        pos = ai.get_next_move()
        end = time.time()
        print(f'GetValue in {round(end - start, 7)}s')
        ai.set_value(pos[0], pos[1], CellState.AI)
        ai.debug()
    send(f"{pos[0]},{pos[1]}")


def beginCmd(_, __):
    global FIRST_TURN

    FIRST_TURN = False
    pos = ai.first_move()
    ai.set_value(pos[0], pos[1], CellState.AI)
    send(f"{pos[0]},{pos[1]}")
    return


def boardCmd(_, __):
    while True:
        line = sys.stdin.readline()
        if (line.strip().split(" ")[0] == "DONE"):
            break
        pos = line.strip().split(",")
        x, y, player = int(pos[0]), int(pos[1]), int(pos[2])
        ai.set_value(x, y, player)
    pos = ai.get_next_move()
    ai.set_value(pos[0], pos[1], CellState.AI)
    send(f'{pos[0]}, {pos[1]}')


def infoCmd(_, __):
    pass


def endCmd(_, __):
    sys.exit(0)


def aboutCmd(_, __):
    global ABOUT
    send(ABOUT)


def main():
    global FIRST_TURN
    switch = {
        "START":  startCmd,
        "TURN":  turnCmd,
        "BEGIN":  beginCmd,
        "BOARD":  boardCmd,
        "INFO":  infoCmd,
        "END":  endCmd,
        "ABOUT":  aboutCmd,
        "RESTART": restartCmd,
    }
    while True:
        commandLine = sys.stdin.readline().strip().replace(
            ",", " ").split(" ")
        if commandLine[0] in switch:
            switch[commandLine[0]]((commandLine[1] if len(
                commandLine) > 1 else 0), (commandLine[2] if len(commandLine) > 2 else 0))
        else:
            send(f"UNKNOWN cannot found command {commandLine[0]}")
    return 0


if __name__ == "__main__":
    if len(sys.argv) > 1 and (sys.argv[1] == "-d" or sys.argv[1] == "--debug"):
        DEBUG = True
        print("============\n DEBUG MODE\n============")
    sys.exit(main())
