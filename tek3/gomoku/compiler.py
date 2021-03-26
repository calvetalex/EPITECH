import os

os.system("pip install pyinstaller")
os.system(
    "pyinstaller brain.py AI.py Board.py CellState.py --name pbrain-gomoku-ai --onefile")
# TODO: copy past this to use AlphaBeta class: "pyinstaller brain.py MinMaxAB.py pattern.py --name pbrain-gomoku-ai --onefile
os.system('copy .\\dist\\pbrain-gomoku-ai.exe .')
