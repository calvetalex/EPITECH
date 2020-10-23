/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** compare two strings and return 0 is they are eguals
*/

#include <unistd.h>
#include <stdlib.h>

char *strlower(char *str);

char *my_strcpy(char *dest, char *src);

int my_strlen(char *str);

int my_strcmp(char *str_first, char *str_sec)
{
    int i = 0;

    for (i = 0; str_first[i] == str_sec[i] && str_first[i] != '\0'; i++)
        if (str_sec[i] == '\0')
            return (1);
    if (str_first[i] > str_sec[i])
        return (1);
    else if (str_first[i] < str_sec[i])
        return (-1);
    else
        return (0);
}
