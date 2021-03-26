#!/usr/bin/env python3

import enum
import math


class BoardState(enum.Enum):
    EMPTY = 0
    AI = 1
    ENNEMY = 2


empty_pattern = "00000"
win_patterns = ["2220", "22202", "2202", "22220", "11011",
                "11110", "11101", "1101", "1110", "110", "101", "10"]

patterns = [
    # AI Patterns
    # Patterns 5
    {
        "pattern": [BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI],
        "weight": math.inf,
        "priority": -1
    },

    # Patterns 4
    {
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI],
        "weight": 4,
        "priority": 0
    },
    {
        "pattern": [BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.AI],
        "weight": 4,
        "priority": 0
    },
    {
        "pattern": [BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.AI],
        "weight": 4,
        "priority": 0
    },
    {
        "pattern": [BoardState.AI, BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.AI],
        "weight": 4,
        "priority": 0
    },
    {
        "pattern": [BoardState.AI, BoardState.AI, BoardState.AI, BoardState.AI, BoardState.EMPTY],
        "weight": 4,
        "priority": 0
    },

    # Patterns 3
    {
        "pattern": [BoardState.AI, BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.EMPTY],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.EMPTY],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY, BoardState.AI],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.AI],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.AI],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.AI, BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.AI],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.AI],
        "weight": 3,
        "priority": 3
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.AI],
        "weight": 3,
        "priority": 3
    },

    # Patterns 2
    # AI 1
    {
        "pattern": [BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": 2,
        "priority": 4
    },
    {
        "pattern": [BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY],
        "weight": 2,
        "priority": 4
    },
    {
        "pattern": [BoardState.AI, BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY],
        "weight": 2,
        "priority": 4
    },
    {
        "pattern": [BoardState.AI, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.AI],
        "weight": 2,
        "priority": 4
    },
    # AI 2
    {
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY],
        "weight": 2,
        "priority": 4
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY],
        "weight": 2,
        "priority": 4
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY, BoardState.AI],
        "weight": 2,
        "priority": 4
    },
    # AI 3
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.AI, BoardState.EMPTY],
        "weight": 2,
        "priority": 4
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.AI],
        "weight": 2,
        "priority": 4
    },
    # AI 4
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.AI],
        "weight": 2,
        "priority": 4
    },


    # Patterns 1
    {
        "pattern": [BoardState.AI, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": 1,
        "priority": 5
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": 1,
        "priority": 5
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY, BoardState.EMPTY],
        "weight": 1,
        "priority": 5
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.AI, BoardState.EMPTY],
        "weight": 1,
        "priority": 5
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.AI],
        "weight": 1,
        "priority": 5
    },


    # ENNEMY Patterns
    # Patterns 1
    {
        "pattern": [BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": -1,
        "priority": 7
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": -1,
        "priority": 7
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": -1,
        "priority": 7
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY],
        "weight": -1,
        "priority": 7
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY],
        "weight": -1,
        "priority": 7
    },

    # Patterns 2
    {
        "pattern": [BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY],
        "weight": -2,
        "priority": 6
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY],
        "weight": -2,
        "priority": 6
    },

    # Patterns 3
    {
        "pattern": [BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY],
        "weight": -3,
        "priority": 2
    },
    {
        "pattern": [BoardState.EMPTY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY],
        "weight": -3,
        "priority": 2
    },

    # Patterns 4
    {
        "pattern": [BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY],
        "weight": -4,
        "priority": 1
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY],
        "weight": -4,
        "priority": 1
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY, BoardState.ENNEMY],
        "weight": -4,
        "priority": 1
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY, BoardState.ENNEMY],
        "weight": -4,
        "priority": 1
    },
    {
        "pattern": [BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.EMPTY],
        "weight": -4,
        "priority": 1
    },


    # Patterns 5
    {
        "pattern": [BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY, BoardState.ENNEMY],
        "weight": -math.inf,
        "priority": -1
    }
]
