#!/usr/bin/env python3
import sys
import random
from pattern import EMPTY_CELL, AI_CELL, ENNEMY_CELL

class AlphaBeta:
    "implementation of min max with alpha beta method"

    __board = []
    __board_size = 0
    __max_length = 0


    def __init__(self, size):
        self.__counter = -1
        self.__board_size = size
        self.__max_length = size - 1
        self.__board = [[EMPTY_CELL] * size for _ in range(size)]

    def __str__(self):
        return f'AI is playing on a board of size {self.__board_size} with minmax algorithm'

    def __repr__(self):
        return f'AlphaBeta({self.__board_size})'

    def __reset(self):
        self.__board = [[EMPTY_CELL] * self.__board_size for _ in range(size)]

    def debug(self):
        for i in range(0, self.__board_size):
            for j in range(0, self.__board_size):
                print(f'{self.__board[i][j]}|', end="")
            print()

    def isValid(self, x, y):
        if x < 0 or x > self.__max_length or y < 0 or y > self.__max_length:
            return False
        return self.__board[x][y] is EMPTY_CELL

    def __checkHorizontal(self, i, j):
        if j + 5 > self.__max_length:
            return None
        if self.__board[i][j:j+5] == [AI_CELL, AI_CELL, AI_CELL, AI_CELL, AI_CELL]:
            return AI_CELL
        elif self.__board[i][j:j+5] == [ENNEMY_CELL, ENNEMY_CELL, ENNEMY_CELL, ENNEMY_CELL, ENNEMY_CELL]:
            return ENNEMY_CELL
        return EMPTY_CELL

    def __checkVertical(self, i, j):
        if i + 4 > self.__max_length:
            return None
        if (self.__board[i][j] != EMPTY_CELL and
            self.__board[i + 1][j] == self.__board[i][j] and
            self.__board[i + 2][j] == self.__board[i + 1][j] and
            self.__board[i + 3][j] == self.__board[i + 2][j] and
            self.__board[i + 4][j] == self.__board[i + 3][j]):
                return self.__board[i][j]
        return EMPTY_CELL

    def __checkDiagonalUp(self, i, j):
        if i + 4 > self.__max_length or j + 4 > self.__max_length:
            return None
        if (self.__board[i][j] !=EMPTY_CELL and
            self.__board[i + 1][j + 1] == self.__board[i][j] and
            self.__board[i + 2][j + 2] == self.__board[i + 1][j + 1] and
            self.__board[i + 3][j + 3] == self.__board[i + 2][j + 2] and
            self.__board[i + 4][j + 4] == self.__board[i + 3][j + 3]):
                return self.__board[i][j]
        return EMPTY_CELL

    def __checkDiagonalDown(self, i, j):
        if i + 4 > self.__max_length or j - 4 < 0:
            return None
        if (self.__board[i][j] != EMPTY_CELL and
            self.__board[i + 1][j - 1] != self.__board[i][j] and
            self.__board[i + 2][j - 2] != self.__board[i + 1][j - 1] and
            self.__board[i + 3][j - 3] != self.__board[i + 2][j - 2] and
            self.__board[i + 4][j - 4] != self.__board[i + 3][j - 3]):
                return self.__board[i][j]
        return EMPTY_CELL

    def __evaluate(self):
        if self.__counter >= 0:
            self.__counter += 1
        isEmpty = False
        for i in range(self.__max_length):
            if AI_CELL in self.__board[i] or ENNEMY_CELL in self.__board[i]:
                for j in range(self.__max_length):
                    state = self.__checkHorizontal(i, j)
                    if state != EMPTY_CELL:
                        return state
                    state = self.__checkVertical(i, j)
                    if state != EMPTY_CELL:
                        return state
                    state = self.__checkDiagonalUp(i, j)
                    if state != EMPTY_CELL:
                        return state
                    state = self.__checkDiagonalDown(i, j)
                    if state != EMPTY_CELL:
                        return state   
            elif EMPTY_CELL in self.__board[i]:
                isEmpty = True
        return EMPTY_CELL if isEmpty == False else None

    def __maxAlphaBeta(self, alpha, beta):
        maxv = -2
        x, y = 0, 0
        res = self.__evaluate()
        
        if res is AI_CELL:
            return (1, 0, 0)
        elif res is ENNEMY_CELL:
            return (-1, 0, 0)
        elif res is EMPTY_CELL:
            return (0, 0, 0)
        for i in range(0, self.__max_length):
            for j in range(0, self.__max_length):
                if self.__board[i][j] == EMPTY_CELL:
                    self.__board[i][j] = AI_CELL
                    (m, minI, minJ) = self.__minAlphaBeta(alpha, beta)
                    if m > maxv:
                        maxv, x, y = m, i, j
                    self.__board[i][j] = EMPTY_CELL
                    if maxv >= beta:
                        return (maxv, x, y)
                    if maxv >= alpha:
                        alpha = maxv
        return (maxv, x, y)

    def __minAlphaBeta(self, alpha, beta):
        minv = 2
        x, y = 0, 0
        res = self.__evaluate()

        if res is AI_CELL:
            return (1, 0, 0)
        elif res is ENNEMY_CELL:
            return (-1, 0, 0)
        elif res is EMPTY_CELL:
            return (0, 0, 0)
        for i in range(0, self.__max_length):
            if AI_CELL in self.__board[i] or ENNEMY_CELL in self.__board[i]:
                for j in range(0, self.__max_length):
                    if self.__board[i][j] == EMPTY_CELL:
                        self.__board[i][j] = ENNEMY_CELL
                        (m, maxI, maxJ) = self.__maxAlphaBeta(alpha, beta)
                        if m < minv:
                            minv, x, y = m, i, j
                        self.__board[i][j] = EMPTY_CELL
                        if minv <= alpha:
                            return (minv, x, y)
                        if minv < beta:
                            beta = minv
        return (minv, x, y)

    def getNextMove(self, alpha=-2, beta=2, debug=False):
        if debug:
            self.__counter = 0
            print("looking for best value....")
        (m, x, y) = self.__maxAlphaBeta(alpha, beta)
        if debug:
            print(f'Got {x} {y} with {self.__counter:,} evaluation of the game')
            print(f'IsValid pos: {self.isValid(x, y)}')
            self.__counter = -1
        if (self.isValid(x, y)):
            return [x, y]
        (m, x, y) = self.__minAlphaBeta(alpha, beta)
        return [x, y]

    def setValue(self, x, y, value):
        self.__board[x][y] = value

    def randomMove(self):
        pos = [random.randint(0, self.__max_length), random.randint(0, self.__max_length)]
        while not self.isValid(pos[0], pos[1]):
            pos = [random.randint(0, self.__max_length),
                   random.randint(0, self.__max_length)]
        return pos