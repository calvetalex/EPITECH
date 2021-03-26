#!/usr/bin/env python3

import random
from math import inf
from .Board import Board
from .CellState import CellState

MAX_DEPTH = 1


class AI:
    def __init__(self, size, win_length=5, strategy="random"):
        self._size = size
        self._win_length = win_length
        self._strategy = strategy
        self._board = Board(size, win_length)

    def debug(self, *args, **kwargs):
        self._board.debug()

    def first_move(self):
        i = self._size // 2
        return i, i

    def _random_coord(self):
        return random.randint(0, self._size - 1)

    def get_value(self, x, y):
        return self._board.get(x, y)

    def set_value(self, x, y, state):
        self._board.set(x, y, state)

    def is_valid_move(self, x, y):
        return self._board.is_valid_move(x, y)

    def reset(self):
        self._board.reset()

    def random_move(self):
        x, y = self._random_coord(), self._random_coord()

        while not self._board.is_valid_move(x, y):
            x, y = self._random_coord(), self._random_coord()
        return x, y

    def _minimax(self, board, depth, alpha, beta, player):
        if depth <= 0 or board.is_game_over():
            return board, board.static_eval()

        if player is CellState.AI:
            maxEval = -inf
            children = board.get_child_boards(player)
            for c in children:
                _, e = self._minimax(c, depth - 1, alpha,
                                     beta, CellState.ENEMY)
                maxEval = max(maxEval, e)
                alpha = max(alpha, e)
                if beta <= alpha:
                    break
            return c, maxEval
        else:
            minEval = inf
            children = board.get_child_boards(player)
            for c in children:
                _, e = self._minimax(c, depth - 1, alpha, beta, CellState.AI)
                minEval = min(minEval, e)
                alpha = min(alpha, e)
                if beta <= alpha:
                    break
            return c, minEval

    def minimax_move(self):
        next_board, _ = self._minimax(self._board, 3, -inf, inf, CellState.AI)
        return self._board.diff(next_board)

    def weighted_move(self):
        weights = self._board.weighted_eval()
        i, max_weight = max(enumerate(weights), key=lambda t: t[1])

        if max_weight == 0:
            return self.random_move()
        return self._board.to_coords(i)

    def get_next_move(self):
        hmap = {
            "random": self.random_move,
            "minimax": self.minimax_move,
            "weighted": self.weighted_move
        }
        func = hmap.get(self._strategy, self.random_move)

        return func()
