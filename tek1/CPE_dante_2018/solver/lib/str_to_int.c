/*
** EPITECH PROJECT, 2018
** str_to_int.c
** File description:
** change a str to an int
*/

#include <stdlib.h>
#include "../include/my.h"

int str_to_int(char *str)
{
    int res = 0;
    int neg = 0;

    if (*str == '-') {
        neg = 1;
        str++;
    }
    while (*str != '\0') {
        if (my_str_isnum(str) == 1)
            return -123;
        res = res * 10 + (*str - '0');
        str++;
    }
    if (neg == 1)
        res = res * -1;
    return (res);
}
