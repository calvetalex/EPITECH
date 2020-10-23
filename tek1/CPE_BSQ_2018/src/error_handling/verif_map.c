/*
** EPITECH PROJECT, 2018
** verif_map.c
** File description:
** verif if the map is good
*/

#include <stdlib.h>
#include "my.h"

int verif_map(game_t *info)
{
    int err = 0;

    for (int i = 0; info->map[i] != NULL; i++)
        if (info->map[i+1] != NULL)
            if (my_strlen(info->map[i+1]) != my_strlen(info->map[i]))
                err = 1;
    for (int i = 0; info->map[i] != NULL; i++)
        for (int j = 0; info->map[i][j] != '\0'; j++)
            if (info->map[i][j] != WALL && info->map[i][j] != EMPTY)
                err = 1;
    if (err == 1)
        return (ERROR);
    else
        return (SUCCESS);
}