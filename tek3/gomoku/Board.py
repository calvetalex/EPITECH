#!/usr/bin/env python3

import copy
from math import inf
from CellState import CellState
from pattern import patterns


class Board:
    def __init__(self, size, win_length=5):
        self._size = size
        self._win_length = win_length
        self._board = [CellState.EMPTY for _ in range(size ** 2)]

    @staticmethod
    def from_string(string, size, win_length=5):
        board = Board(size, win_length)
        board._board = [CellState.from_char(c) for c in string]

        return board

    def get_size(self):
        return self._size

    def set(self, x, y, state):
        self._board[y * self._size + x] = state

    def get(self, x, y):
        return self._board[y * self._size + x]

    def to_coords(self, i):
        x, y = i % self._size, i // self._size

        return x, y

    def is_valid_move(self, x, y):
        return self.get(x, y) is CellState.EMPTY

    def contains(self, state):
        return state in self._board

    def reset(self):
        self._board = [CellState.EMPTY for _ in range(self._size ** 2)]

    def debug(self):
        s = self.to_string(self._board)

        print(s)

    @staticmethod
    def to_string(row):
        return ''.join(CellState.to_char(cell) for cell in row)

    def get_rows(self):
        return [self.to_string(self._board[i * self._size:(i + 1) * self._size]) for i in range(self._size)]

    def get_cols(self):
        # transpose the board with zip
        rows = self.get_rows()
        return [''.join(s) for s in zip(*rows)]

    def get_diagonals(self):
        # https://stackoverflow.com/questions/23069388/listing-elements-in-a-nested-lists-diagonally
        diagonals = [[self.get(q, self._size - p + q - 1) for q in range(max(
            p - self._size + 1, 0), min(p + 1, self._size))] for p in range(2 * self._size - 1)]

        diagonals = filter(lambda line: len(line) >=
                           self._win_length, diagonals)
        return [self.to_string(row) for row in diagonals]

    def get_antidiagonals(self):
        # https://stackoverflow.com/questions/23069388/listing-elements-in-a-nested-lists-diagonally
        diagonals = [[self.get(q, p - q) for q in range(max(p - self._size + 1, 0),
                                                        min(p + 1, self._size))] for p in range(2 * self._size - 1)]
        diagonals = filter(lambda line: len(line) >=
                           self._win_length, diagonals)
        return [self.to_string(row) for row in diagonals]

    def who_won(self):
        rows = self.get_rows()
        cols = self.get_cols()
        diagonals = self.get_diagonals()
        antidiagonals = self.get_antidiagonals()
        win_ai = CellState.to_char(CellState.AI) * self._win_length
        win_enemy = CellState.to_char(CellState.ENEMY) * self._win_length

        if win_ai in rows or win_ai in cols or win_ai in diagonals or win_ai in antidiagonals:
            return CellState.AI
        if win_enemy in rows or win_enemy in cols or win_enemy in diagonals or win_enemy in antidiagonals:
            return CellState.ENEMY
        return CellState.EMPTY

    def is_game_over(self):
        return not self.contains(CellState.EMPTY) or self.who_won() is not CellState.EMPTY

    def get_child_boards(self, player):
        boards = []
        for y in range(self._size):
            for x in range(self._size):
                if self.get(x, y) is CellState.EMPTY:
                    new_board = copy.deepcopy(self)
                    new_board.set(x, y, player)
                    boards.append(new_board)
        return boards

    def diff(self, board):
        for i in range(self._size ** 2):
            x, y = self.to_coords(i)
            if board.get(x, y) is not self._board[i]:
                return x, y

    def occurrences(string, sub):
        count = start = 0
        while True:
            start = string.find(sub, start) + 1
            if start > 0:
                count += 1
            else:
                return count

    def static_eval(self):
        win_ai = CellState.to_char(CellState.AI) * self._win_length
        win_enemy = CellState.to_char(CellState.AI) * self._win_length

        rows = self.get_rows()
        cols = self.get_cols()
        diagonals = self.get_diagonals()
        antidiagonals = self.get_antidiagonals()

        if win_ai in rows or win_ai in cols or win_ai in diagonals or win_ai in antidiagonals:
            return inf
        elif win_enemy in rows or win_enemy in cols or win_enemy in diagonals or win_enemy in antidiagonals:
            return -inf

        total = 0
        # Make it extremely slow
        for p in patterns.patterns:
            for row in rows:
                total += row.count(p["pattern"]) * p["weight"]
            for col in cols:
                total += col.count(p["pattern"]) * p["weight"]
            for diagonal in diagonals:
                total += diagonal.count(p["pattern"]) * p["weight"]
            for antidiagonal in antidiagonals:
                total += antidiagonal.count(p["pattern"]) * p["weight"]

        return total

    def _right(self, start):
        row = start // self._size

        return range(start + 1, min(start + self._win_length, (row + 1) * self._size))

    def _down_right(self, start):
        row = start // self._size
        col = start % self._size

        m = max(row, col)
        for i in range(m, min(self._size - 1, m + self._win_length - 1)):
            yield (i - m + 1 + row) * (self._size + 1) + col - row

    def _down(self, start):
        row = start // self._size

        return range(start + self._size, start + min(self._win_length, self._size - row) * self._size, self._size)

    def _down_left(self, start):
        row = start // self._size
        col = start % self._size

        m = min(self._size - row - 1, col)
        for i in range(row, row + min(m, self._win_length - 1)):
            yield (i + 1) * (self._size - 1) + col + row

    def _left(self, start):
        row = start // self._size

        return range(start - 1, max(start - self._win_length, row * self._size - 1), -1)

    def _up_left(self, start):
        row = start // self._size
        col = start % self._size

        m = min(row, col)
        for i in range(row - 1, row - 1 - min(self._win_length - 1,  m), -1):
            yield (i) * (self._size + 1) + col - row

    def _up(self, start):
        return range(start - self._size, max(start - self._win_length * self._size, -1), -self._size)

    def _up_right(self, start):
        row = start // self._size
        col = start % self._size

        m = min(row, self._size - col - 1)
        for i in range(m, max(0, m - self._win_length + 1), -1):
            yield start - (m - i + 1) * (self._size - 1)

    def _add_weight(self, start, weights, direction):
        hmap = {
            "right": self._right,
            "down right": self._down_right,
            "down": self._down,
            "down left": self._down_left,
            "left": self._left,
            "up left": self._up_left,
            "up": self._up,
            "up right": self._up_right,
        }
        func = hmap.get(direction)
        if not func:
            return

        cells_in_a_row = 1
        for i in func(start):
            if self._board[i] is self._board[start]:
                cells_in_a_row += 1
            elif self._board[i] is not CellState.EMPTY:
                cells_in_a_row = 0
                break
        for i in func(start):
            if self._board[i] is CellState.EMPTY:
                if self._board[start] is CellState.ENEMY:
                    weights[i] += cells_in_a_row
                    break
                elif cells_in_a_row >= self._win_length - 1:
                    weights[i] = inf

    def weighted_eval(self):
        weights = [0 for _ in range(self._size ** 2)]

        for i, c in enumerate(self._board):
            if c is not CellState.EMPTY:
                self._add_weight(i, weights, "right")
                self._add_weight(i, weights, "down right")
                self._add_weight(i, weights, "down")
                self._add_weight(i, weights, "down left")
                self._add_weight(i, weights, "left")
                self._add_weight(i, weights, "up left")
                self._add_weight(i, weights, "up")
                self._add_weight(i, weights, "up right")
        return weights
