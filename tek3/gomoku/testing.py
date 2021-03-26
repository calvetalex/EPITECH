#!/usr/bin/env python3
from ia import *
from brain import *


# section = lambda name: print(f'''
#     +-----------------------------------+
#         => {name}
#     +-----------------------------------+
# ''')
# title = lambda msg: print(f'\n=======================\n{msg}\n=======================')

# RESET    = '\33[0m'

# BLACK  = '\33[30m'
# RED    = '\33[31m'
# BLUE   = '\33[34m'
# GREY    = '\33[90m'

# UNDERLINE = '\33[4m'

# RED_2    = '\33[101m'
# BLUE_2   = '\33[104m'
# GREY_2    = '\33[100m'

# GREY_BG    = '\33[100m'
# RED_BG    = '\33[101m'
# GREEN_BG2  = '\33[102m'
# YELLOW_BG2 = '\33[103m'
# BLUE_BG2   = '\33[104m'
# VIOLET_BG = '\33[105m'
# BEIGE_BG  = '\33[106m'
# WHITE_BG  = '\33[107m'


# colors = {
#     0: GREY_BG,
#     1: RED_BG,
#     2: GREEN_BG2,
#     3: YELLOW_BG2,
#     4: BLUE_BG2,
#     5: VIOLET_BG,
#     6: BEIGE_BG,
#     7: WHITE_BG,
#     }


# # class BoardState(enum.Enum):
# #     EMPTY = 0
# #     AI = 1
# #     ENNEMY = 2

# def print_board(board):
#     title("BOARD")
#     print(f"{BLUE}AI{RESET}")
#     print(f"{RED}ENNEMY{RESET}")
#     print()

#     print("Line(y)/Row(x)\t", end="")
#     print(f"{UNDERLINE}[", end="")
#     for i in range(len(board)):
#         if i > 0:
#             if i < 11:
#                 print("    ,", end="")
#             else:
#                 print("   ,", end="")
#         print(f"{i}", end="")
#     print(f"   ]{RESET}")


#     for y in range(len(board)):
#         print(f"{y} :\t\t[", end="")
#         for x in range(len(board[y])):
#             if x != 0:
#                 print(",", end="")
#             if board[y][x] == BoardState.AI or board[y][x] == BoardState.AI:
#                 # print(f"{BLUE}{board[y][x]}{RESET}", end="")
#                 print(f"{BLACK}{BLUE_2}  A  {RESET}", end="")
#             elif board[y][x] == BoardState.ENNEMY:
#                 # print(f"{RED}{board[y][x]}{RESET}", end="")
#                 print(f"{BLACK}{RED_2}  E  {RESET}", end="")
#             elif colors.__contains__(board[y][x]):
#                 # print(f"{RED}{board[y][x]}{RESET}", end="")
#                 print(f"{colors.get(board[y][x])}     {RESET}", end="")
#             else:
#                 # print(f"{GREY}{board[y][x]}{RESET}", end="")
#                 print(f"     ", end="")
#         print("]")
#     title("END BOARD")

board = []

isErr = False


def test_start():
    global board, isErr
    section("START")
    title("CREATE EMPTY BOARD")
    play_board, computation_board = start(0)
    #print(f'play board: {play_board}\ncomputatio board: {computation_board}\n')
    print(f'IS COPY OF PLAY BOARD: {play_board == computation_board}')
    if isErr == False:
        isErr = play_board != computation_board
    title("CREATE VALID BOARD")
    play_board, computation_board = start(19)
    if isErr == False:
        isErr = play_board != computation_board
    #print(f'play board: {play_board}\ncomputatio board: {computation_board}\n')
    #print(f"BOARD :\n{play_board}\n")
    print(f'IS COPY OF PLAY BOARD: {play_board == computation_board}')
    board = play_board
    title("CREATE INVALID BOARD")
    play_board, computation_board = start(-5)
    if isErr == False:
        isErr = play_board != computation_board
    #print(f'play board: {play_board}\ncomputatio board: {computation_board}\n')
    print(f'IS COPY OF PLAY BOARD: {play_board == computation_board}')


def test_isValid():
    global board, isErr
    section("IS VALID")
    title("VALID POS")
    if (isValid(board, 0, 0) == True):
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True
    title("INVALID POS")
    board[0][0] = BoardState.ENNEMY
    if isValid(board, 0, 0) == False:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True
    title("OUT OF THE BOARD")
    if (isValid(board, -1, -1) == False):
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True


def test_setBoard():
    global board, isErr
    section("SET BOARD")
    title("VALID POSITION")
    set_board(board, 1, 1, BoardState.AI)
    if (board[1][1] == BoardState.AI):
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True
    title("INVALID POS")
    set_board(board, -1, 2, BoardState.AI)
    if (board[1][1] == BoardState.AI):
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True
    title("INVALID VALUE")
    print("This test is optional, don't take care of it if you don't want an extrem error handling")
    set_board(board, 2, 2, BoardState.AI)
    if (board[2][2] == BoardState.AI):
        print("test OK")
    else:
        print("/!\\ test KO /!\\")


def test_get_coord_from_position():
    global isErr
    section("GET COORD FROM POS")
    moveOptionsHorizontal = {
        "position": [12, 13],
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.AI],
        "value": 1000000,
        "orientation": Orientation.HORIZONTAL
    }
    moveOptionsVertical = {
        "position": [12, 13],
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.AI],
        "value": 1000000,
        "orientation": Orientation.VERTICAL
    }
    moveOptionsDiagonalRight = {
        "position": [12, 13],
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.AI],
        "value": 1000000,
        "orientation": Orientation.DIAGONAL_LEFT_TO_RIGHT
    }
    moveOptionsDiagonalLeft = {
        "position": [12, 13],
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.AI],
        "value": 1000000,
        "orientation": Orientation.DIAGONAL_RIGHT_TO_LEFT
    }
    title("HORIZONTAL_LOWER")
    pos = get_coord_from_position(moveOptionsHorizontal)
    if (pos[0] == 10 and pos[1] == 13):
        print("test OK")
    else:
        print(f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]}")
        isErr = True
    title("HORIZONTAL_HIGHER")
    pos = get_coord_from_position({
        "position": [12, 13],
        "pattern": [BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI, BoardState.EMPTY],
        "value": 1000000,
        "orientation": Orientation.HORIZONTAL
    })
    if (pos[0] == 14 and pos[1] == 13):
        print("test OK")
    else:
        print(
            f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]} instead of x=14 y=13")
        isErr = True
    title("VERTICAL_LOWER")
    pos = get_coord_from_position(moveOptionsVertical)
    if (pos[0] == 12 and pos[1] == 11):
        print("test OK")
    else:
        print(f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]}")
        isErr = True
    title("VERTICAL_HIGHER")
    pos = get_coord_from_position({
        "position": [12, 13],
        "pattern": [BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI, BoardState.EMPTY],
        "value": 1000000,
        "orientation": Orientation.VERTICAL
    })
    if (pos[0] == 12 and pos[1] == 15):
        print("test OK")
    else:
        print(
            f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]} instead of x=14 y=13")
        isErr = True
    title("DIAGONALE RIGHT LOWER")
    pos = get_coord_from_position(moveOptionsDiagonalRight)
    if (pos[0] == 10 and pos[1] == 11):
        print("test OK")
    else:
        print(f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]}")
        isErr = True
    title("DIAGONALE RIGHT HIGHER")
    moveOptionsDiagonalRight["pattern"] = [
        BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI, BoardState.EMPTY]
    pos = get_coord_from_position(moveOptionsDiagonalRight)
    if (pos[0] == 14 and pos[1] == 15):
        print("test OK")
    else:
        print(f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]}")
        isErr = True
    title("DIAGONALE LEFT LOWER")
    pos = get_coord_from_position(moveOptionsDiagonalLeft)
    if (pos[0] == 10 and pos[1] == 15):
        print("test OK")
    else:
        print(f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]}")
        isErr = True
    title("DIAGONALE LEFT HIGHER")
    moveOptionsDiagonalLeft["pattern"] = [
        BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI, BoardState.EMPTY]
    pos = get_coord_from_position(moveOptionsDiagonalLeft)
    if (pos[0] == 14 and pos[1] == 11):
        print("test OK")
    else:
        print(f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]}")
        isErr = True
    title("FULL PATTERN")
    pos = get_coord_from_position({
        "position": [12, 13],
        "pattern": [BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI],
        "value": 1000000,
        "orientation": Orientation.VERTICAL
    })
    if pos == None:
        print("test OK")
    else:
        print(
            f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]} instead of x=14 y=13")
        isErr = True
    title("EMPTY BOARD")
    pos = get_coord_from_position({
        "position": [12, 13],
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY],
        "value": 1000000,
        "orientation": Orientation.VERTICAL
    })
    if pos[0] == 12 and pos[1] == 13:
        print("test OK")
    else:
        print(
            f"/!\\ test KO /!\\ Got: x= {pos[0]} and y={pos[1]} instead of x=14 y=13")
        isErr = True


def test_get_pattern():
    global isErr
    section("GET PATTERN")
    title("valid pattern")
    res = getPattern([BoardState.AI, BoardState.AI,
                      BoardState.AI, BoardState.AI, BoardState.EMPTY])
    if res["weight"] == 4:
        print("test OK")
    else:
        print(f"/!\\ test KO /!\\ Got {res}")
        isErr = True
    title("INVALID PATTERN")
    res = getPattern([BoardState.AI])
    if res == 0:
        print("test OK")
    else:
        print(f"/!\\ test KO /!\\ Got {res}")
        isErr = True


def test_get_move_horizontal():
    global board, isErr
    board[3][3] = BoardState.AI
    section("MOVE HORIZONTAL")
    title("GET VALID MOVE")
    move = get_move_horizontal(3, 3, board, False)
    if move["pattern"] == [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY]:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True
    title("GET INVALID MOVE")
    move = get_move_horizontal(0, 3, board, False)
    if move == 0:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True


def test_get_move_vertical():
    global board, isErr
    board[5][5] = BoardState.AI
    section("MOVE VERTICAL")
    move = get_move_vertical(5, 5, board, False)
    if move["pattern"] == [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY]:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True
    title("GET INVALID MOVE")
    move = get_move_vertical(5, 2, board, False)
    if move == 0:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True


def test_get_move_diagonal_ltor():
    global board, isErr
    board[10][10] = BoardState.AI
    section("MOVE DIAGONAL LEFT TO RIGHT")
    move = get_move_diagonal_ltor(10, 10, board, False)
    if move["pattern"] == [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY]:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True
    title("GET INVALID MOVE")
    move = get_move_diagonal_ltor(5, 2, board, False)
    if move == 0:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True


def test_get_move_diagonal_rtol():
    global board, isErr
    board[11][11] = BoardState.AI
    section("MOVE DIAGONAL RIGHT TO LEFT")
    move = get_move_diagonal_rtol(11, 11, board, False)
    if move["pattern"] == [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY]:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True
    title("GET INVALID MOVE")
    move = get_move_diagonal_rtol(5, 2, board, False)
    if move == 0:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True


def test_evaluation():
    global board
    section("EVAL")
    title("FUNCTIONAL TEST")
    print_board(board)
    print(f"Eval = {evaluation(board, 1)}")

    title("MAX UPPER VALUE")

    modulo = 5
    equals = 4

    # Modulo x Equal == Evaluation
    # 5x4 == 3144
    # 5x3 == 3024
    # 5x2 == 3024
    # 5x1 == 3024
    # 5x0 == 3024

    # 4x3 == 3012
    # 4x2 == 2823
    # 4x1 == 2824
    # 4x0 == 2823

    # 3x2 == 1220
    # 3x1 == 1220
    # 3x0 == 1180

    # 2x1 == 1340
    # 2x0 == 1216

    test_board, _ = start(19)
    for y in range(len(test_board)):
        if (y % modulo) == equals:
            continue
        for x in range(len(test_board[y])):
            if (x % modulo) == equals:
                continue
            test_board[y][x] = BoardState.AI

    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("Game Is Over. Test Cancelled")
        return

    print_board(test_board)  # 651 upgrade paterns found
    print(f"Eval ({modulo}x{equals}) = {evaluation(test_board, 1)}")

    # title("MAX LOWER VALUE")
    # test_board, _ = start(19)

    # for y in range (len(test_board)):
    #     if (y % modulo) == equals:
    #         continue
    #     for x in range (len(test_board[y])):
    #         if (x % modulo) == equals:
    #             continue
    #         test_board[y][x] = BoardState.ENNEMY
    # print_board(test_board)
    # print(f"Eval = {evaluation(test_board, 1)}")


def test_game_over():
    global board, isErr
    section("GAME OVER")

    title("NOT OVER")
    has_game_over = game_over(board)
    if has_game_over == False:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True

    title("OVER HORIZONTAL AI")
    test_board, _ = start(19)
    test_board[0][0] = BoardState.AI
    test_board[0][1] = BoardState.AI
    test_board[0][2] = BoardState.AI
    test_board[0][3] = BoardState.AI
    test_board[0][4] = BoardState.AI
    # print_board(test_board)
    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True

    title("OVER VERTICAL AI")
    test_board, _ = start(19)
    test_board[0][0] = BoardState.AI
    test_board[1][0] = BoardState.AI
    test_board[2][0] = BoardState.AI
    test_board[3][0] = BoardState.AI
    test_board[4][0] = BoardState.AI
    # print_board(test_board)
    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True

    title("OVER DIAGONAL L2R AI")
    test_board, _ = start(19)
    test_board[0][0] = BoardState.AI
    test_board[1][1] = BoardState.AI
    test_board[2][2] = BoardState.AI
    test_board[3][3] = BoardState.AI
    test_board[4][4] = BoardState.AI
    # print_board(test_board)
    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True

    title("OVER DIAGONAL R2L AI")
    test_board, _ = start(19)
    test_board[0][4] = BoardState.AI
    test_board[1][3] = BoardState.AI
    test_board[2][2] = BoardState.AI
    test_board[3][1] = BoardState.AI
    test_board[4][0] = BoardState.AI
    # print_board(test_board)
    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True

    title("OVER HORIZONTAL ENNEMY")
    test_board, _ = start(19)
    test_board[0][0] = BoardState.ENNEMY
    test_board[0][1] = BoardState.ENNEMY
    test_board[0][2] = BoardState.ENNEMY
    test_board[0][3] = BoardState.ENNEMY
    test_board[0][4] = BoardState.ENNEMY
    # print_board(test_board)
    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True

    title("OVER VERTIACAL ENNEMY")
    test_board, _ = start(19)
    test_board[0][0] = BoardState.ENNEMY
    test_board[1][0] = BoardState.ENNEMY
    test_board[2][0] = BoardState.ENNEMY
    test_board[3][0] = BoardState.ENNEMY
    test_board[4][0] = BoardState.ENNEMY
    # print_board(test_board)
    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True

    title("OVER DIAGONAL L2R ENNEMY")
    test_board, _ = start(19)
    test_board[0][0] = BoardState.ENNEMY
    test_board[1][1] = BoardState.ENNEMY
    test_board[2][2] = BoardState.ENNEMY
    test_board[3][3] = BoardState.ENNEMY
    test_board[4][4] = BoardState.ENNEMY
    # print_board(test_board)
    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True

    title("OVER DIAGONAL R2L ENNEMY")
    test_board, _ = start(19)
    test_board[0][4] = BoardState.ENNEMY
    test_board[1][3] = BoardState.ENNEMY
    test_board[2][2] = BoardState.ENNEMY
    test_board[3][1] = BoardState.ENNEMY
    test_board[4][0] = BoardState.ENNEMY
    # print_board(test_board)
    has_game_over = game_over(test_board)
    if has_game_over == True:
        print("test OK")
    else:
        print("/!\\ test KO /!\\")
        isErr = True


def position_toStr(pos):
    pos_str = ""
    pos_str = pos_str + "Position:" + "\n"
    pos_str = pos_str + f"value:{pos['value']}" + "\n"
    pos_str = pos_str + \
        f"x:{pos['position'][0]} | y:{pos['position'][1]}" + "\n"
    pos_str = pos_str + f"Pattern:{patern_toStr(pos['pattern'])}" + "\n"
    pos_str = pos_str + f"Orientation:{pos['orientation']}"


def test_select_best_pos():
    def print_position(pos):
        print("Position:")
        print(f"value:{pos['value']}")
        print(f"x:{pos['position'][0]} | y:{pos['position'][1]}")
        print(f"Pattern:{patern_toStr(pos['pattern'])}")
        print(f"Orientation:{pos['orientation']}")
        print()

    global test_board
    section("BEST MOVES SELECTION")
    # test_board, _ = start(19)

    # 0,0
    test_board, _ = start(19)
    test_board[2][2] = BoardState.AI

    title("One in a Row")
    print_board(test_board)
    positions = select_best_pos(test_board, 1, 20)

    print(f"nb_Positions : {len(positions)}")
    positions = filter(lambda position: position["value"] == 1, positions)
    for pos in positions:
        print_position(pos)

    # 0,3
    test_board, _ = start(19)
    test_board[2][12] = BoardState.AI
    test_board[1][13] = BoardState.AI
    test_board[3][13] = BoardState.AI
    test_board[3][10] = BoardState.AI

    title("Two in a Row")
    print_board(test_board)
    positions = select_best_pos(test_board, 1, 20)

    print(f"nb_Positions : {len(positions)}")
    positions = filter(lambda position: position["value"] == 2, positions)
    for pos in positions:
        print_position(pos)

    # 3,0
    test_board, _ = start(19)
    test_board[12][2] = BoardState.AI

    test_board[11][2] = BoardState.AI
    test_board[14][2] = BoardState.AI

    test_board[10][0] = BoardState.AI
    test_board[10][4] = BoardState.AI
    test_board[14][0] = BoardState.AI
    test_board[14][4] = BoardState.AI

    title("Three in a Row")
    print_board(test_board)
    positions = select_best_pos(test_board, 1, 20)

    print(f"nb_Positions : {len(positions)}")
    positions = filter(lambda position: position["value"] == 3, positions)
    for pos in positions:
        print_position(pos)

    # 3,3
    test_board, _ = start(19)
    test_board[12][12] = BoardState.AI

    test_board[10][12] = BoardState.AI
    test_board[13][12] = BoardState.AI
    test_board[14][12] = BoardState.AI

    test_board[10][10] = BoardState.AI
    test_board[11][11] = BoardState.AI
    test_board[14][14] = BoardState.AI
    test_board[10][13] = BoardState.AI
    test_board[10][14] = BoardState.AI
    test_board[13][11] = BoardState.AI
    test_board[14][10] = BoardState.AI

    title("Four in a Row")
    print_board(test_board)
    positions = select_best_pos(test_board, 1, 20)

    print(f"nb_Positions : {len(positions)}")
    positions = filter(lambda position: position["value"] == 4, positions)
    for pos in positions:
        print_position(pos)


def test_minimax():
    global board
    board, _ = start(19)
    a = random.randint(0, 18)
    b = random.randint(0, 18)
    c = random.randint(0, 18)
    d = random.randint(0, 18)
    e = random.randint(0, 18)
    f = random.randint(0, 18)
    # print_board(board)
    print(f"a = {a} | b = {b} | c = {c} | d = {d} | e = {e} | f = {f}")
    # board[a][b] = BoardState.ENNEMY
    board[c][d] = BoardState.AI
    # print_board(board)
    # board[e][f] = BoardState.ENNEMY
    mycopy = []
    for line in board:
        mycopy.append(copy.deepcopy(line))
    # eval_debug()debug_minimax
    print(
        f" best move to do is {debug_minimax(mycopy, [a,b], random.randint(5, 20), -math.inf, math.inf, BoardState.AI)}")


def main():
    global isErr
    ##
    # /!\ TODO /!\
    # test function minmax for depth 0
    ##
    print("TESTING SCRIPT")
    # test_start()
    # print()
    # test_isValid()
    # print()
    # test_setBoard()
    # print()
    # test_get_coord_from_position()
    # print()
    # test_get_pattern()
    # print()
    # test_get_move_horizontal()
    # print()
    # test_get_move_vertical()
    # print()
    # test_get_move_diagonal_ltor()
    # print()
    # test_get_move_diagonal_rtol()
    # print()
    # test_evaluation()
    # print()
    # test_game_over()
    # print()
    # test_select_best_pos()
    # print()
    test_minimax()
    print()
    return 0 if not isErr else 84


if __name__ == "__main__":
    exit(main())
