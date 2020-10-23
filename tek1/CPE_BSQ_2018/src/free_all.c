/*
** EPITECH PROJECT, 2018
** free_all.c
** File description:
** free all malloc variables
*/

#include <stdlib.h>
#include "my.h"

void free_all(game_t *info, char *file)
{
    free(file);
    if (info->map != NULL) {
        for (int i = 0; info->map[i] != NULL; i++)
            free(info->map[i]);
        free(info->map);
    }
}