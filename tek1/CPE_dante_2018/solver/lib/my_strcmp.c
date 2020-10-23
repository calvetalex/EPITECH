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

int my_strcmp(char *str1, char *str2)
{
    char *str_first = NULL;
    char *str_sec = NULL;
    int i = 0;

    str_first = malloc(sizeof(char) * my_strlen(str1));
    str_first = my_strcpy(str_first, str1);
    str_sec = malloc(sizeof(char) * my_strlen(str2));
    str_sec = my_strcpy(str_sec, str2);
    str_first = strlower(str_first);
    str_sec = strlower(str_sec);
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
