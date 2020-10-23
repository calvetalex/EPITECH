/*
** EPITECH PROJECT, 2018
** find_player.c
** File description:
** return the player position in str
*/

#include "my.h"

int find_player(char *str)
{
    int place = 0;

    while (*str != 'P' && *str != '\0') {
        place++;
        str++;
    }
    return (place);
}
