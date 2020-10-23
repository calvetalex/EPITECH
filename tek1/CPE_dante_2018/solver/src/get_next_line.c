/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** take next line
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int my_strlen(char *str)
{
    int nb = 0;

    if (str == NULL)
        return (0);
    for (; str[nb] != '\0'; nb++);
    return (nb);
}

char *my_strcat(char *str, char *add, int nb)
{
    char *string = NULL;
    int len = my_strlen(str) + nb;
    int i = 0;

    string = malloc(sizeof(char) * (len + 1));
    string[len] = '\0';
    if (string == NULL || len == 0)
        return (NULL);
    for (; i < my_strlen(str); i++)
        string[i] = str[i];
    for (int j = 0; j < nb; j++, i++)
        string[i] = add[j];
    return (string);
}

char *frag_str(char *str, char **keep)
{
    char *string = NULL;
    int len = 0;
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (; str[len] != '\n' && str[len] != '\0'; len++);
    string = malloc(sizeof(char) * (len + 1));
    *keep = malloc(sizeof(char) * (my_strlen(str) - len));
    if (*keep == NULL || string == NULL)
        return (NULL);
    (*keep)[my_strlen(str) - len - 1] = '\0';
    string[len] = '\0';
    if (my_strlen(str) == len)
        *keep = NULL;
    for (; i < len; i++)
        string[i] = str[i];
    for (int j = 0; i + 1 < my_strlen(str); i++, j++)
        (*keep)[j] = str[i + 1];
    return (string);
}

int check_str(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i] != '\0'; i++)
        if (str[i] == '\n')
            return (1);
    return (0);
}

char *get_next_line(int fd)
{
    static char *keep = NULL;
    char *str = NULL;
    char *buffer = NULL;
    int read_v = 1;

    buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    if (buffer == NULL || READ_SIZE <= 0 || fd == -1)
        return (NULL);
    if (keep != NULL) {
        str = my_strcat(keep, NULL, 0);
        keep = NULL;
    }
    for (int verif = 0; verif == 0 && read_v > 0;verif = check_str(str) {
        read_v = read(fd, buffer, READ_SIZE);
        str = my_strcat(str, buffer, read_v);
    }
    str = frag_str(str, &keep);
    return (str);
}
