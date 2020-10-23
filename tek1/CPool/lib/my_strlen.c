/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** display the numbers of char in a string
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (*str != '\0'){
        i++;
        str++;
    }
    return (i);
}

int tablen(char **tab)
{
    int len = 0;

    if (tab == NULL)
        return (-1);
    for (len = 0; tab[len] != NULL; len = len+1);
    return (len);
}