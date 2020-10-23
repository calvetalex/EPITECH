/*
** EPITECH PROJECT, 2018
** vertical_move.c
** File description:
** config to move up and down
*/

#include "my.h"

int len_line(char *str)
{
    int ret = 0;

    while (*str != '\n') {
        ret++;
        str++;
    }
    return (ret);
}

void move_up(char *str)
{
    int place = find_player(str);
    int line = len_line(str) + 1;
    char save;

    if (str[place - line] == ' ') {
        save = str[place - line];
        str[place - line] = str[place];
        str[place] = save;
    }
    if (str[place - line] == 'X') {
        if (str[place - (line * 2)] == 'O')
            iswinup(str, place, line);
        if (str[place - (line * 2)] == ' ') {
            save = str[place - (line * 2)];
            str[place - (line * 2)] = str[place - line];
            str[place - line] = str[place];
            str[place] = save;
        }
    }
}

void move_down(char *str)
{
    int place = find_player(str);
    int line = len_line(str) + 1;
    char save;

    if (str[place + line] == ' ') {
        save = str[place + line];
        str[place + line] = str[place];
        str[place] = save;
    }
    if (str[place + line] == 'X') {
        if (str[place + (line * 2)] == 'O')
            iswindown(str, place, line);
        if (str[place + (line * 2)] == ' ') {
            save = str[place + (line * 2)];
            str[place + (line * 2)] = str[place + line];
            str[place + line] = str[place];
            str[place] = save;
        }
    }
}
