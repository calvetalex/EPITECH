/*
** EPITECH PROJECT, 2018
** iswin.c
** File description:
** test win conditions
*/

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int findo(char *str)
{
    int target = 0;

    while (*str != '\0') {
        if (*str == 'O')
            target++;
        str++;
    }
    return (target);
}

int iswinup (char *str, int place, int line)
{
    int target = 0;

    str[place - (line * 2)] = str[place - line];
    str[place - line] = str[place];
    str[place] = ' ';
    target = findo(str);
    if (target == 0)
        exit (1);
    return (0);
}

int iswindown(char *str, int place, int line)
{
    int target = 0;

    str[place + (line * 2)] = str[place + line];
    str[place + line] = str[place];
    str[place] = ' ';
    target = findo(str);
    if (target == 0)
        exit (1);
    return (0);
}

int iswinleft(char *str, int place)
{
    int target = 0;

    str[place - 2] = str[place - 1];
    str[place - 1] = str[place];
    str[place] = ' ';
    target = findo(str);
    if (target == 0)
        exit (1);
    return (0);
}

int iswinright(char *str, int place)
{
    int target = 0;

    str[place + 2] = str[place + 1];
    str[place + 1] = str[place];
    str[place] = ' ';
    target = findo(str);
    if (target == 0)
        exit (1);
    return (0);
}
