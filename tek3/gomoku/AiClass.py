#!/usr/bin/env python3
import random
from pattern import win_patterns, EMPTY_CELL, AI_CELL, ENNEMY_CELL


class customAi():
    board_size = 0
    play_board = []

    def __init__(self, size):
        self.board_size = size
        self.play_board = [[EMPTY_CELL] * size for _ in range(size)]

    def __str__(self):
        return f"Custom AI Instance: playing on board of {self.board_size}"

    def __repr__(self):
        return f"customAi({self.board_size})"

    def reset(self):
        self.play_board = [[EMPTY_CELL] *
                           self.board_size for _ in range(self.board_size)]

    def debug(self):
        for i in range(0, self.board_size):
            for j in range(0, self.board_size):
                print(f'{self.play_board[i][j]}|', end="")
            print()

    def firstMove(self):
        for line in self.play_board:
            if AI_CELL in line:
                pos = self.getNextMove()
                self.play_board[pos[0]][pos[1]] = AI_CELL
                return pos
        mid = int(self.board_size / 2) - 1
        if self.isValid(mid, mid):
            self.play_board[mid][mid] = AI_CELL
            return [mid, mid]
        else:
            self.play_board[mid + 1][mid] = AI_CELL
            return [mid, mid + 1]

    def isValid(self, x, y):
        if x < 0 or x > self.board_size - 1 or y < 0 or y > self.board_size - 1:
            return False
        return self.play_board[y][x] is EMPTY_CELL

    def setValue(self, x, y, value):
        self.play_board[y][x] = value

    def randomMove(self):
        pos = [random.randint(0, self.board_size - 1),
               random.randint(0, self.board_size - 1)]
        while not self.isValid(pos[0], pos[1]):
            pos = [random.randint(0, self.board_size - 1),
                   random.randint(0, self.board_size - 1)]
        return pos

    def getNextMove(self):
        for case in win_patterns:
            for y in range(self.board_size):
                for x in range(self.board_size):
                    if (self.play_board[y][x] is AI_CELL or self.play_board[y][x] is ENNEMY_CELL):
                        pos = self._checkPatterns(case, x, y)
                        if pos and self.isValid(pos[0], pos[1]):
                            return pos
        return self.randomMove()

    def _checkPatterns(self, pattern, x, y):
        pos = self._horizontalCheck(pattern, x, y)
        if pos:
            return pos
        pos = self._verticalCheck(pattern, x, y)
        if pos:
            return pos
        pos = self._diagonalRightCheck(pattern, x, y)
        if pos:
            return pos
        pos = self._diagonalLeftCheck(pattern, x, y)
        if pos:
            return pos
        return None

    def _horizontalCheck(self, pattern, x, y):
        maxRange = x + len(pattern)
        pos = None
        for i in range(x, maxRange):
            if (i > self.board_size - 1) or (self.play_board[y][i] is not pattern[i - x]):
                pos = None
                break
            if pattern[x - i] is EMPTY_CELL:
                pos = [i, y]
        if pos:
            return pos
        maxRange = x - len(pattern)
        for i in range(x, maxRange, -1):
            if i < 0 or (self.play_board[y][i] is not pattern[-(i - x)]):
                pos = None
                break
            if pattern[(-(i - x))] is EMPTY_CELL:
                pos = [i, y]
        return pos

    def _verticalCheck(self, pattern, x, y):
        maxRange = y + len(pattern)
        pos = None
        for i in range(y, maxRange):
            if i > self.board_size - 1 or (self.play_board[i][x] != pattern[i - y]):
                pos = None
                break
            if pattern[i - y] is EMPTY_CELL:
                pos = [x, i]
        if pos:
            return pos
        maxRange = y - len(pattern)
        for i in range(y, maxRange, -1):
            if i < 0 or self.play_board[i][x] is not pattern[-(i - y)]:
                pos = None
                break
            if pattern[-(i - y)] is EMPTY_CELL:
                pos = [x, i]
        return pos

    def _diagonalLeftCheck(self, pattern, x, y):
        maxRange = len(pattern)
        pos = None
        for i in range(0, maxRange):
            if y - i < 0 or x + i > self.board_size - 1 or self.play_board[y - i][x + i] is not pattern[i]:
                pos = None
                break
            if pattern[i] is EMPTY_CELL:
                pos = [x + i, y - i]
        if pos:
            return pos
        for i in range(0, maxRange):
            if y - i < 0 or x - i < 0 or self.play_board[y - i][x - i] is not pattern[i]:
                pos = None
                break
            if pattern[i] is EMPTY_CELL:
                pos = [x - i, y - i]
        return pos

    def _diagonalRightCheck(self, pattern, x, y):
        maxRange = len(pattern)
        pos = None
        for i in range(0, maxRange):
            if y + i > self.board_size - 1 or x - i < 0 or self.play_board[y + i][x - i] is not pattern[i]:
                pos = None
                break
            if pattern[i] is EMPTY_CELL:
                pos = [x - i, y + x]
        if pos:
            return pos
        for i in range(0, maxRange):
            if y + i > self.board_size - 1 or x + i > self.board_size - 1 or self.play_board[y + i][x + i] is not pattern[i]:
                pos = None
                break
            if pattern[i] is EMPTY_CELL:
                pos = [x + i, y + i]
        return pos
        
