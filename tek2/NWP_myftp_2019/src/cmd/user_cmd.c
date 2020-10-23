/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** user_cmd
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"

void user_cmd(char **tab, clt_t *client)
{
    if (tab[0] && !tab[1] && client->rights != 7)
        dprintf(client->fd, "530 Permission denied\n");
    else if (client->rights == 7)
        dprintf(client->fd, "530 user already connected\n");
    else {
        free(client->user);
        client->rights = 0;
        client->user = strdup(tab[1]);
        dprintf(client->fd, "331 Please specify your password\n");
    }
}