#!/usr/bin/env python3
import copy
import enum
import math
import random
import pattern as Patterns


class Minimax():
    n_branch = 4
    board_size = 0
    play_board = []

    class Orientation(enum.Enum):
        HORIZONTAL = 0
        VERTICAL = 1
        DIAGONAL_LEFT_TO_RIGHT = 2
        DIAGONAL_RIGHT_TO_LEFT = 3

    def __init__(self, size):
        self.board_size = size
        self.play_board = [[Patterns.BoardState.EMPTY]
                           * size for _ in range(size)]

    def __str__(self):
        return f"Minimax Class Instance: get a board of {self.board_size} and look for {self.n_branch} branches"

    def __repr__(self):
        return f"Minimax({self.board_size})"

    def reset(self):
        self.play_board = [[Patterns.BoardState.EMPTY] *
                           self.board_size for _ in range(self.board_size)]

    def generateBoardCopy(self):
        boardCopy = []
        for line in self.play_board:
            boardCopy.append(copy.deepcopy(line))
        return boardCopy

    def setValue(self, x, y, value):
        if x < 0 or x >= len(self.play_board) - 1 or y < 0 or y >= len(self.play_board) - 1:
            return
        self.play_board[y][x] = value

    def isValid(self, x, y):
        if x < 0 or x >= len(self.play_board) - 1 or y < 0 or y >= len(self.play_board) - 1:
            return False
        return self.play_board[y][x] == Patterns.BoardState.EMPTY

    def minimax(self, board, played_position, depth, alpha, beta, player_turn):
        if (played_position == None):
            return self._evaluation(board, Patterns.BoardState.AI), None
        if player_turn == Patterns.BoardState.AI:
            self.setValue(
                played_position[0], played_position[1], Patterns.BoardState.ENNEMY)
        else:
            self.setValue(
                played_position[0], played_position[1], Patterns.BoardState.AI)
        is_game_over = self._game_over(board)
        if depth == 0 or is_game_over:
            if is_game_over:
                if player_turn == Patterns.BoardState.AI:
                    return (-math.inf), None
                else:
                    return (math.inf), None
            static_eval = self._evaluation(board, Patterns.BoardState.AI)
            return static_eval, None
        if player_turn == Patterns.BoardState.AI:
            maxEval = -math.inf
            best_pos = None
            for selected_position in self._select_best_pos(board, player_turn):
                current_eval, _ = self.minimax(copy.deepcopy(board), self._get_coord_from_position(
                    selected_position), depth - 1, alpha, beta, Patterns.BoardState.ENNEMY)
                if current_eval > maxEval:
                    best_pos = selected_position
                maxEval = max(maxEval, current_eval)
                alpha = max(alpha, current_eval)
                if beta <= alpha or maxEval == math.inf:
                    break
            try:
                return maxEval, self._get_coord_from_position(best_pos)
            except:
                return maxEval, None
        else:
            minEval = math.inf
            for selected_position in self._select_best_pos(board, player_turn):
                current_eval, _ = self.minimax(copy.deepcopy(board), self._get_coord_from_position(
                    selected_position), depth - 1, alpha, beta, Patterns.BoardState.AI)
                minEval = min(minEval, current_eval)
                beta = min(beta, current_eval)
                if beta <= alpha or minEval == -math.inf:
                    break
            return minEval, None

    def _get_coord_from_position(self, moveOptions):
        if (moveOptions["pattern"] == Patterns.empty_pattern):
            return moveOptions["position"]
        playNearAI = -1
        x, y = moveOptions["position"][0], moveOptions["position"][1]
        orient = moveOptions["orientation"]
        size = len(moveOptions["pattern"])
        mid = int(size / 2)
        emptyPlaces = [i for i, x in enumerate(
            moveOptions["pattern"]) if x == Patterns.BoardState.EMPTY]
        if len(emptyPlaces) == 0:
            return None
        elif len(emptyPlaces) == 1:
            playNearAI = emptyPlaces[0]
        elif len(emptyPlaces) == size:
            playNearAI = mid
        else:
            length = len(moveOptions["pattern"])
            for i in range(0, length):
                if moveOptions["pattern"][i] == Patterns.BoardState.AI or moveOptions["pattern"][i] == Patterns.BoardState.ENNEMY:
                    if i > 0 and moveOptions["pattern"][i - 1] == Patterns.BoardState.EMPTY:
                        playNearAI = i - 1
                        break
                    if i < (length - 1) and moveOptions["pattern"][i + 1] == Patterns.BoardState.EMPTY:
                        playNearAI = i + 1
                        break
        if playNearAI == -1:
            return None
        if orient == self.Orientation.HORIZONTAL:
            if playNearAI > mid:
                x += (playNearAI - mid)
            else:
                for _ in range(playNearAI, mid):
                    x -= 1
        elif orient == self.Orientation.VERTICAL:
            if playNearAI > mid:
                y += (playNearAI - mid)
            else:
                for _ in range(playNearAI, mid):
                    y -= 1
        elif orient == self.Orientation.DIAGONAL_RIGHT_TO_LEFT:
            if playNearAI > mid:
                x += (playNearAI - mid)
                y += (playNearAI - mid)
            else:
                for _ in range(playNearAI, mid):
                    x -= 1
                    y -= 1
        elif orient == self.Orientation.DIAGONAL_LEFT_TO_RIGHT:
            if playNearAI > mid:
                x += (playNearAI - mid)
                y -= (playNearAI - mid)
            else:
                for _ in range(playNearAI, mid):
                    x -= 1
                    y += 1
        if x < 0 or x > len(self.play_board) or y < 0 or y > len(self.play_board):
            while self.isValid(x, y) == False:
                x, y = random.randint(1, 19), random.randint(1, 19)
        return [x, y]

    def _get_move_horizontal(self, x, y, board, win_only, player):
        if x < 2 or x > len(board) - 3 or y > len(board):
            return None
        board_slice = board[y][(x - 2):(x + 2 + 1)]
        if player == Patterns.BoardState.ENNEMY:
            if board_slice.__contains__(Patterns.BoardState.AI):
                board_slice = [Patterns.BoardState.ENNEMY if x ==
                               Patterns.BoardState.AI else x for x in board_slice]
            elif board_slice.__contains__(Patterns.BoardState.ENNEMY):
                board_slice = [Patterns.BoardState.AI if x ==
                               Patterns.BoardState.AI else x for x in board_slice]
        return (self._getPattern(board_slice, win_only))

    def _get_move_vertical(self, x, y, board, win_only, player):
        if (y < 2 or y > len(board) - 3) or x > len(board[0]):
            return None
        board_slice = []
        for i in range(-2, 3):
            board_slice.append(board[y + i][x])
        if player == Patterns.BoardState.ENNEMY:
            if board_slice.__contains__(Patterns.BoardState.AI):
                board_slice = [Patterns.BoardState.ENNEMY if x ==
                               Patterns.BoardState.AI else x for x in board_slice]
            elif board_slice.__contains__(Patterns.BoardState.ENNEMY):
                board_slice = [Patterns.BoardState.AI if x ==
                               Patterns.BoardState.AI else x for x in board_slice]
        return (self._getPattern(board_slice, win_only))

    def _get_move_diagonal_ltor(self, x, y, board, win_only, player):
        if (x < 2 or x > len(board) - 3) or (y < 2 or y > len(board) - 3):
            return None
        board_slice = []
        for i in range(-2, 3):
            board_slice.append(board[y + i][x + i])
        if player == Patterns.BoardState.ENNEMY:
            if board_slice.__contains__(Patterns.BoardState.AI):
                board_slice = [Patterns.BoardState.ENNEMY if x ==
                               Patterns.BoardState.AI else x for x in board_slice]
            elif board_slice.__contains__(Patterns.BoardState.ENNEMY):
                board_slice = [Patterns.BoardState.AI if x ==
                               Patterns.BoardState.AI else x for x in board_slice]
        return (self._getPattern(board_slice, win_only))

    def _get_move_diagonal_rtol(self, x, y, board, win_only, player):
        if (x < 2 or x > len(board) - 3) or (y < 2 or y > len(board) - 3):
            return None
        board_slice = []
        for i in range(-2, 3):
            board_slice.append(board[y - i][x + i])
        if player == Patterns.BoardState.ENNEMY:
            if board_slice.__contains__(Patterns.BoardState.AI):
                board_slice = [Patterns.BoardState.ENNEMY if x ==
                               Patterns.BoardState.AI else x for x in board_slice]
            elif board_slice.__contains__(Patterns.BoardState.ENNEMY):
                board_slice = [Patterns.BoardState.AI if x ==
                               Patterns.BoardState.AI else x for x in board_slice]
        return (self._getPattern(board_slice, win_only))

    def _getPattern(self, mySlice, win_only):
        if win_only:
            selected_paterns = filter(
                lambda x: x["priority"] == -1, Patterns.patterns)
        else:
            selected_paterns = Patterns.patterns
        for elem in selected_paterns:
            if elem["pattern"] == mySlice:
                return elem
        return None

    def _game_over(self, board):
        for i in range(len(board)):
            for j in range(len(board[i])):
                horizontal = self._get_move_horizontal(
                    j, i, board, True, Patterns.BoardState.AI)
                vertical = self._get_move_vertical(
                    j, i, board, True, Patterns.BoardState.AI)
                diagonal_ltor = self._get_move_diagonal_ltor(
                    j, i, board, True, Patterns.BoardState.AI)
                diagonal_rtol = self._get_move_diagonal_rtol(
                    j, i, board, True, Patterns.BoardState.AI)
                if horizontal != None or vertical != None or diagonal_ltor != None or diagonal_rtol != None:
                    return True
        return False

    def _random_move(self, board):
        length = len(board)
        for i in range(length):
            for j in range(length):
                if (board[i][j] == Patterns.BoardState.EMPTY):
                    return [{
                        "position": [j, i],
                        "pattern": Patterns.empty_pattern,
                        "value": math.inf,
                        "orientation": self.Orientation.HORIZONTAL
                    }]
        return None

    def _select_best_pos(self, board, player_turn):
        possible_moves = []
        for i in range(len(board)):
            for j in range(len(board[i])):
                horizontal = self._get_move_horizontal(
                    j, i, board, False, player_turn)
                vertical = self._get_move_vertical(
                    j, i, board, False, player_turn)
                diagonal_ltor = self._get_move_diagonal_ltor(
                    j, i, board, False, player_turn)
                diagonal_rtol = self._get_move_diagonal_rtol(
                    j, i, board, False, player_turn)
                if horizontal != None:
                    possible_moves.append({
                        "position": [j, i],
                        "pattern": horizontal["pattern"],
                        "value": horizontal["priority"],
                        "orientation": self.Orientation.HORIZONTAL
                    })
                if vertical != None:
                    possible_moves.append({
                        "position": [j, i],
                        "pattern": vertical["pattern"],
                        "value": vertical["priority"],
                        "orientation": self.Orientation.VERTICAL
                    })
                if diagonal_ltor != None:
                    possible_moves.append({
                        "position": [j, i],
                        "pattern": diagonal_ltor["pattern"],
                        "value": diagonal_ltor["priority"],
                        "orientation": self.Orientation.DIAGONAL_LEFT_TO_RIGHT
                    })
                if diagonal_rtol != None:
                    possible_moves.append({
                        "position": [j, i],
                        "pattern": diagonal_rtol["pattern"],
                        "value": diagonal_rtol["priority"],
                        "orientation": self.Orientation.DIAGONAL_RIGHT_TO_LEFT
                    })
        if len(possible_moves) > 0:
            possible_moves = sorted(possible_moves, key=lambda c: c["value"])
            if len(possible_moves) > self.n_branch:
                possible_moves = possible_moves[:self.n_branch]
        else:
            possible_moves = self._random_move(board)
        return possible_moves

    def _evaluation(self, board, player_turn):
        eval_value = 0
        for i in range(len(board)):
            for j in range(len(board[i])):
                horizontal = self._get_move_horizontal(
                    j, i, board, False, Patterns.BoardState.AI)
                vertical = self._get_move_vertical(
                    j, i, board, False, Patterns.BoardState.AI)
                diagonal_ltor = self._get_move_diagonal_ltor(
                    j, i, board, False, Patterns.BoardState.AI)
                diagonal_rtol = self._get_move_diagonal_rtol(
                    j, i, board, False, Patterns.BoardState.AI)
                if horizontal != None:
                    eval_value = eval_value + (horizontal["weight"])
                if vertical != None:
                    eval_value = eval_value + (vertical["weight"])
                if diagonal_ltor != None:
                    eval_value = eval_value + (diagonal_ltor["weight"])
                if diagonal_rtol != None:
                    eval_value = eval_value + (diagonal_rtol["weight"])
        return eval_value
