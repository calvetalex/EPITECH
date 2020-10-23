/*
** EPITECH PROJECT, 2019
** display_free.c
** File description:
** display function and free char **
*/

#include <stdlib.h>
#include "my.h"

void make_exit(gen_t *d)
{
    int random = rand()%15;

    d->maze[d->height-1][d->width-1] = '*';
    if (d->maze[d->height-2][d->width-1] != '*' && \
    d->maze[d->height-1][d->width-2] != '*') {
        if (random % 2 == 0)
            d->maze[d->height-2][d->width-1] = '*';
        else
            d->maze[d->height-1][d->width-2] = '*';
    }
}

void place_path(gen_t *d)
{
    for (int i = 0; d->maze[i] != NULL; i++)
        for (int j = 0; d->maze[i][j] != '\0'; j++)
            if (d->maze[i][j] == ' ')
                d->maze[i][j] = '*';
}

void disp_maze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        my_putstr(maze[i]);
        if (maze[i+1] != NULL)
            my_putchar('\n');
    }
}

void freechar(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        free(maze[i]);
    free(maze);
}