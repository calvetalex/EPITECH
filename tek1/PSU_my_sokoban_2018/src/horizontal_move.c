/*
** EPITECH PROJECT, 2018
** horizontal_move.c
** File description:
** config to move to the right and to the left
*/

#include "my.h"

void move_right(char *str)
{
    int place = find_player(str);
    char save;

    if (str[place + 1] == ' ') {
        save = str[place + 1];
        str[place + 1] = str[place];
        str[place] = save;
    }
    if (str[place + 1] == 'X') {
        if (str[place + 2] == 'O')
            iswinright(str, place);
        if (str[place + 2] == ' ') {
            save = str[place + 2];
            str[place + 2] = str[place + 1];
            str[place + 1] = str[place];
            str[place] = save;
        }
    }
}

void move_left(char *str)
{
    int place = find_player(str);
    char save;

    if (str[place - 1] == ' ') {
        save = str[place - 1];
        str[place - 1] = str[place];
        str[place] = save;
    }
    if (str[place - 1] == 'X') {
        if (str[place - 2] == 'O')
            iswinleft(str, place);
        if (str[place - 2] == ' ') {
            save = str[place - 2];
            str[place - 2] = str[place - 1];
            str[place - 1] = str[place];
            str[place] = save;
        }
    }
}
