#!/bin/env python3

import asyncio
import time
import threading
from enum import Enum
from .Gui import Gui
from . import brain


class CellState(Enum):
    EMPTY = None
    CROSS = False
    CIRCLE = True

    def to_victory_string(self):
        return "CROSS (X)" if self is CellState.CROSS else "CIRCLE (O)"

    @staticmethod
    def toState(b):
        return CellState.CIRCLE if b else CellState.CROSS

    @staticmethod
    def next(state):
        hmap = {
            CellState.EMPTY: CellState.EMPTY,
            CellState.CIRCLE: CellState.CROSS,
            CellState.CROSS: CellState.CIRCLE,
        }

        return hmap.get(state)


class Board():
    def __init__(self, n=5, cell_size=80, line_thickness=10, win_length=5, start_player=False, cross=None, circle=None):
        # initialising game
        self._n = n
        self._win_length = win_length
        self._init_board()

        self._current = CellState.toState(start_player)  # current player
        self.cross_path = cross  # path to AI file
        self.circle_path = circle
        self.is_running = True  # is game running

        # initialising window
        self._init_window(n, cell_size, line_thickness)

    def _init_board(self):
        self._board = [[CellState.EMPTY for _ in range(
            self._n)] for _ in range(self._n)]

    def _init_window(self, n, cell_size, line_thickness):
        self._gui = Gui(self, n, cell_size, line_thickness)

    def mouse1_trigger(self, row, col):
        if self._board[row][col] is CellState.EMPTY:
            # update board cell
            self._board[row][col] = self._current

            # draw changes
            if self._current is CellState.CROSS:
                self._gui.draw_cross(row, col)
            else:
                self._gui.draw_circle(row, col)

            # check for victory
            if self._check_victory(self._current):
                self._gui.disable_mouse_click()
                self._gui.draw_message(
                    self._current.to_victory_string() + " WINS")

            # next player's turn
            self._current = CellState.next(self._current)

    def _check_victory(self, current):
        hmap = {CellState.EMPTY: ' ', CellState.CROSS: 'X',
                CellState.CIRCLE: 'O', }

        def to_string(row):
            return ''.join(map(lambda c: hmap[c], row))

        def get_rows(board):
            return [to_string(row) for row in board]

        def get_cols(board):
            # transpose the board with zip
            return [to_string(s) for s in zip(*board)]

        def get_diagonals(board, n):
            # https://stackoverflow.com/questions/23069388/listing-elements-in-a-nested-lists-diagonally
            diagonals = [to_string(board[n - p + q - 1][q] for q in range(max(p - n + 1, 0), min(p + 1, n)))
                         for p in range(2 * n - 1)]

            diagonals = filter(lambda line: len(line) >=
                               self._win_length, diagonals)

            return diagonals

        def get_antidiagonals(board, n):
            # https://stackoverflow.com/questions/23069388/listing-elements-in-a-nested-lists-diagonally
            diagonals = [to_string(board[p - q][q] for q in range(max(p - n + 1, 0), min(p + 1, n)))
                         for p in range(2 * n - 1)]
            diagonals = filter(lambda line: len(line) >=
                               self._win_length, diagonals)

            return diagonals

        win = hmap[current] * self._win_length

        return (any(win in row for row in get_rows(self._board)) or
                any(win in row for row in get_cols(self._board)) or
                any(win in row for row in get_diagonals(self._board, self._n)) or
                any(win in row for row in get_antidiagonals(self._board, self._n)))

    async def _run(self):
        cross_ai = await brain.create_process(
            self.cross_path) if self.cross_path else None
        circle_ai = await brain.create_process(
            self.circle_path) if self.circle_path else None

        # if AI exists but could not be launched
        if cross_ai is not None and cross_ai.returncode is not None:
            raise brain.BrainException(
                f"Could not start process {self.cross_path}")
        if circle_ai is not None and circle_ai.returncode is not None:
            raise brain.BrainException(
                f"Could not start process {self.circle_path}")

        while self.is_running:
            print("batman")
            time.sleep(1)

        if cross_ai:
            cross_ai.kill()
            await cross_ai.wait()
        if circle_ai:
            circle_ai.kill()
            await circle_ai.wait()

    def run(self):
        self._gui.run()
        asyncio.run(self._run())
