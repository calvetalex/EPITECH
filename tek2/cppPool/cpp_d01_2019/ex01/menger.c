/*
** EPITECH PROJECT, 2020
** menger
** File description:
** algorithic functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./menger.h"

void menger_display(int size, int x, int y)
{
    printf("%03d %03d %03d\n", size, y, x);
}

void menger_exec(int size, int level, int x, int y)
{
    int square = size / 3;

    if (size > level && size / 3 != 0 && level > 0) {
        menger_display(square, x + square, y + square);
        level -= 1;
        menger_exec(square, level, x, y);
        menger_exec(square, level, x + square, y);
        menger_exec(square, level, x + 2 * square, y);
        menger_exec(square, level, x, y + square);
        menger_exec(square, level, x + 2 * square, y + square);
        menger_exec(square, level, x, y + 2 * square);
        menger_exec(square, level, x + square, y + 2 * square);
        menger_exec(square, level, x + 2 * square, y + 2 * square);
    }
}

int menger(char **argv)
{
    const int size = atoi(argv[1]);
    const int level = atoi(argv[2]);

    if (level < 1) {
        fprintf(stderr, "Level must be positive\n");
        return (EXIT_ERROR);
    }
    if (size < 0 || size % (int)pow(3, level) != 0) {
        fprintf(stderr, "Size is positive and multiple of 3^level\n");
        return (EXIT_ERROR);
    }
    menger_exec(size, level, 0, 0);
    return (EXIT_SUCCESS);
}