/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** pass_cmd
*/

#include <string.h>
#include <stdio.h>
#include "serveur.h"

static void log_user(char **tab, clt_t *client)
{
    if (client->rights == 7)
        dprintf(client->fd, "230 user already connected\n");
    else if (strcmp(client->user, "Anonymous") != 0)
        dprintf(client->fd, "530 user unknown\n");
    else {
        dprintf(client->fd, "230 Login successful\n");
        client->rights = 7;
    }
    (void)tab;
}

void pass_cmd(char **tab, clt_t *client)
{
    if (client->rights != -1)
        log_user(tab, client);
    else
        dprintf(client->fd, "332 User not specified\n");
}