#!/bin/env python3

from threading import Thread
import tkinter as tk


class Gui(Thread):
    def __init__(self, board, n=5, cell_size=80, line_thickness=10):
        Thread.__init__(self)
        self.start()

        # reference to the parent container
        self._board_ref = board

        # board size
        self._n = n
        # Size of one cell (in pixels)
        self._cell_size = cell_size
        # Thickness of lines (in pixels)
        self._line_thickness = line_thickness
        # Window size
        self.size = cell_size * n + line_thickness * (n + 1)

        # intiliasing the window
        self._window = tk.Tk()
        self._window.title(f"Guimoku ({n}x{n})")
        self._window.geometry(f"{self.size}x{self.size}")
        self._window.resizable(False, False)

        # init the canvas to draw the elements on
        self._canvas = tk.Canvas(
            self._window, height=self.size, width=self.size, bg="grey")
        self._canvas.pack(fill=tk.BOTH, expand=True)
        self._canvas.bind("<Configure>", self._draw_grid)
        self._canvas.bind("<Button-1>", self._mouse1_trigger)

    def _mouse1_trigger(self, event):
        row = self._get_index_from_coord(event.y)
        col = self._get_index_from_coord(event.x)

        self._board_ref.mouse1_trigger(row, col)

    def _get_coord_from_index(self, i):
        return (i + 0.5) * self._cell_size + (i + 1) * self._line_thickness

    def _get_index_from_coord(self, c):
        offset = self._line_thickness // 2
        return int(((c - offset) / self.size) * self._n)

    def _draw_grid(self, _):
        offset = self._line_thickness // 2

        for i in range(offset, self.size + self._line_thickness, self._cell_size + self._line_thickness):
            self._canvas.create_line(
                [(i, 0), (i, self.size)], width=self._line_thickness)
            self._canvas.create_line(
                [(0, i), (self.size, i)], width=self._line_thickness)

    def draw_cross(self, row, col):
        if row < 0 or row >= self._n or col < 0 or col >= self._n:
            return
        x = self._get_coord_from_index(col)
        y = self._get_coord_from_index(row)
        r = 0.8 * (self._cell_size - self._line_thickness) / 2
        self._canvas.create_line(
            [(x - r, y - r), (x + r, y + r)], width=self._line_thickness, fill="red")
        self._canvas.create_line(
            [(x + r, y - r), (x - r, y + r)], width=self._line_thickness, fill="red")

    def draw_circle(self, row, col):
        if row < 0 or row >= self._n or col < 0 or col >= self._n:
            return
        x = self._get_coord_from_index(col)
        y = self._get_coord_from_index(row)
        r = 0.8 * (self._cell_size - self._line_thickness) / 2
        self._canvas.create_oval(x - r, y - r, x + r,
                                 y + r, width=self._line_thickness, outline="green")

    def disable_mouse_click(self):
        self._canvas.unbind("<Button-1>")

    def draw_message(self, msg):
        coords = [(self._line_thickness, self.size / 2),
                  (self.size - self._line_thickness, self.size / 2)]
        font_size = max(1, int(self.size / len(msg)))
        font = f"Roboto {font_size} bold"

        self._canvas.create_line(coords, width=self._cell_size, fill="#606060")
        self._canvas.create_text(
            self.size / 2, self.size / 2, text=msg, fill="white",
            font=font)

    def run(self):
        self._window.mainloop()
