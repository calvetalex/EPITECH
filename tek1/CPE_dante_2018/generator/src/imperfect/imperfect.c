/*
** EPITECH PROJECT, 2019
** generator.c
** File description:
** imperfect maze generator
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "my.h"

void break_walls(gen_t *d)
{
    int random = 0;

    for (int i = 0; d->maze[i] != NULL; i++)
        for (int j = 0; d->maze[i][j] != '\0'; j++) {
            random = rand() % 5;
            if (random %2 == 0)
                d->maze[i][j] = '*';
        }
}

int imperfect(int width, int height)
{
    int col = 0;
    int line = 0;
    gen_t dante = (gen_t) { height, width, col, line, NULL};

    dante.maze = init_maze(height, width);
    srand(time(NULL));
    make_perfect(&dante);
    break_walls(&dante);
    disp_maze(dante.maze);
    freechar(dante.maze);
    return (SUCCESS);
}
