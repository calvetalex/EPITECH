/*
** EPITECH PROJECT, 2020
** debug
** File description:
** debug function -> printf without buffer
*/

#include <stdio.h>

void debug(char *msg)
{
    setbuf(stdout, NULL);
    printf(msg);
    return;
}