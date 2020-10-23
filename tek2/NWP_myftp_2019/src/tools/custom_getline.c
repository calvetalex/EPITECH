/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** custom_getline
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "serveur.h"

static void get_rule(int fd, int *readed, int *len, char *save)
{
    if (*readed <= *len) {
        *readed = read(fd, save, 4);
        *len = 0;
    }
}

static int return_value(char *res, int readed, int *len, int cmp)
{
    if (cmp == 0 && readed == 0)
        return (0);
    *len += 1;
    res[cmp] = '\0';
    return (1);
}

char *my_gnl(int fd)
{
    char save_cmd[5] = {'\0'};
    int len = 1;
    int readed = 1;
    int cmp = 0;
    char *res = NULL;

    if (fd == -1)
        return (NULL);
    res = malloc(sizeof(*res) * 100);
    if (!res)
        return (NULL);
    while (readed != 0 && save_cmd[len] != '\n') {
        get_rule(fd, &readed, &len, save_cmd);
        while (readed > len && save_cmd[len] != '\n')
            res[cmp++] = save_cmd[len++];
    }
    if (return_value(res, readed, &len, cmp) == 0)
        return (NULL);
    return (res);
}