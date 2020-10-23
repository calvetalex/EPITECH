/*
** EPITECH PROJECT, 2018
** disp_use.c
** File description:
** display usage
*/
#include "my.h"

int disp_use(void)
{
    my_printf("USAGE\n\t./my_sokoban map\n");
    my_printf("DESCRIPTION\n\tmap  file representing the warehouse map, \
containing '#' for walls,\n\t     'P' for the player, 'X' for boxes and '0' \
for storage locations\n");
}
