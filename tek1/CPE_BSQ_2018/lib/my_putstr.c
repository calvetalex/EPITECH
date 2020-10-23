/*
** EPITECH PROJECT, 2018
** mu_putstr.c
** File description:
** display string's char one by one
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    if (str != NULL)
        write(1, str, my_strlen(str));
    return (0);
}

int my_puterr(char const *str)
{
    if (str != NULL)
        write(2, str, my_strlen(str));
    return (0);
}