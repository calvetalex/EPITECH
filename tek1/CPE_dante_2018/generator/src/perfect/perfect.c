/*
** EPITECH PROJECT, 2019
** generator.c
** File description:
** perfect maze generator
*/

#include <stdlib.h>
#include <time.h>
#include "my.h"

char **init_maze(int widht, int height)
{
    char **maze = NULL;

    maze = malloc(sizeof(char *) * (height+1));
    if (maze == NULL)
        return (NULL);
    maze[height] = NULL;
    for (int i = 0; i <= (height-1); i++) {
        maze[i] = malloc(sizeof(char) * (widht+1));
        if (maze[i] == NULL)
            return (NULL);
        for (int j = 0; j < widht; j++)
            maze[i][j] = WALL;
        maze[i][widht] = '\0';
    }
    return (maze);
}

void perfect(int width, int height)
{
    int start_col = 0;
    int start_line = 0;
    gen_t dante = (gen_t) { height, width, start_col, start_line, NULL};

    dante.maze = init_maze(height, width);
    srand(time(NULL));
    make_perfect(&dante);
    disp_maze(dante.maze);
    freechar(dante.maze);
}
