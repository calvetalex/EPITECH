#!/usr/bin/env python3

from enum import Enum


class CellState(Enum):
    EMPTY = 0
    AI = 1
    ENEMY = 2

    @staticmethod
    def from_char(c):
        hmap = {
            "0": CellState.EMPTY,
            "1": CellState.AI,
            "2": CellState.ENEMY,
        }

        return hmap.get(c)

    @staticmethod
    def to_char(c):
        hmap = {
            CellState.EMPTY: "0",
            CellState.AI: "1",
            CellState.ENEMY: "2",
        }

        return hmap.get(c)

    @staticmethod
    def opposite_type(c):
        hmap = {
            CellState.EMPTY: CellState.EMPTY,
            CellState.ENEMY: CellState.AI,
            CellState.AI: CellState.ENEMY,
        }

        return hmap.get(c)
