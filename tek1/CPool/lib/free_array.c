/*
** EPITECH PROJECT, 2018
** free_tab.c
** File description:
** free word array
*/

#include <stdlib.h>

void free_array(char **str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}