/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** alloc memory to copy a string
*/
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    if (src == NULL)
        return (NULL);
    while (src[i] != '\0')
        i++;
    str = malloc(sizeof(char) * (i+1));
    if (!str)
        return (NULL);
    for (int j = 0; j < i; j++)
        str[j] = src[j];
    str[i] = '\0';
    return (str);
}
