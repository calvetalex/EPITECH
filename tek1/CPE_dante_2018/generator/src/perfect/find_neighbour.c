/*
** EPITECH PROJECT, 2019
** find_neighbour.c
** File description:
** perfect maze generator
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int is_out(gen_t *d, int x, int y)
{
    if (x < 0 || x >= d->width || \
        y < 0 || y >= d->height)
        return (1);
    return (0);
}

int is_wall(gen_t *d, int x, int y)
{
    if (is_out(d, x, y) == 1 || d->maze[y][x] == WALL)
        return (1);
    return (0);
}

int is_carvable(gen_t *d, int x, int y)
{
    int north = 0;
    int south = 0;
    int west = 0;
    int east = 0;

    if (is_out(d, x, y) == 1 || d->maze[y][x] == CORRIDOR)
        return (0);
    north = is_wall(d, x, y-1);
    south = is_wall(d, x, y+1);
    west = is_wall(d, x-1, y);
    east = is_wall(d, x+1, y);
    if ((north+south+west+east) < 3)
        return (0);
    return (1);
}

void go_back(stack_t **stack, gen_t *d, int *neighbour)
{
    while (*stack != NULL && (find_neighbour(d, neighbour)) == 0) {
        pop_off(stack);
        if (*stack != NULL) {
            d->col = (*stack)->col;
            d->line = (*stack)->line;
        }
    }
}

int find_neighbour(gen_t * d, int *test)
{
    test[0] = is_carvable(d, d->col, d->line-1);
    test[1] = is_carvable(d, d->col, d->line+1);
    test[2] = is_carvable(d, d->col-1, d->line);
    test[3] = is_carvable(d, d->col+1, d->line);
    for (int i = 0; i < 4; i++)
        if (test[i] == 1)
            return (1);
    return (0);
}