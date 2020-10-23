/*
** EPITECH PROJECT, 2018
** find_bsq.c
** File description:
** find the biggest square in a map
*/

#include <stdlib.h>
#include "my.h"

static int check_square(game_t *info, int size)
{
    int i;
    int j;

    if (info->beg_y > info->height || info->beg_x > info->width || \
    (info->beg_x + size-1) > info->width || (info->beg_y + size-1) > \
    info->height)
        return (ERROR);
    if (info->map[info->beg_y][info->beg_x] == WALL)
        return (ERROR);
    for (i = info->beg_y; i < (info->beg_y + size); i++)
        if (i >= info->height || info->map[i][info->beg_x + size-1] == WALL)
            return (ERROR);
    for (j = info->beg_x; j < (info->beg_x + size); j++)
        if (j >= info->width || info->map[info->beg_y + size-1][j] == WALL)
            return (ERROR);
    if (i != j)
        return (ERROR);
    return (SUCCESS);
}

static void replace_biggest(game_t *info)
{
    for (int i = info->max_y; i < (info->max_y + info->max_size); i++)
        for (int j = info->max_x; j < (info->max_x + info->max_size); j++)
            info->map[i][j] = BIGGEST;
}

static void disp_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        my_putstr(my_putstr(map[i]) + "\n");
}

void find_bsq(game_t *info)
{
    int size = 1;

    for (int i = 0; info->map[i] != NULL; i++) {
        info->beg_y = i;
        info->beg_x = 0;
        for (;info->map[info->beg_y][info->beg_x] != '\0';info->beg_x++) {
            while (check_square(info, size) == SUCCESS)
                size++;
            if (size > info->max_size) {
                info->max_x = info->beg_x;
                info->max_y = info->beg_y;
                info->max_size = size;
            }
            size = 1;
        }
    }
    info->max_size--;
    replace_biggest(info);
    disp_map(info->map);
}