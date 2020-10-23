/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** pwd_cmd
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"

void pwd_cmd(char **tab, clt_t *client)
{
    char *path = NULL;

    if (client->rights <= 0)
        dprintf(client->fd, "530 Login first by using USER and PASS\n");
    else {
        path = malloc(sizeof(*path) * 200);
        path = getcwd(path, 200);
        if (!path)
            dprintf(client->fd, "404 directory couldn't be found\n");
        else
            dprintf(client->fd, "257 pwd: %s\n", path);
        if (path)
            free(path);
    }
    (void)tab;
}