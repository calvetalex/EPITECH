/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** noop_cmd
*/

#include <stdio.h>
#include "serveur.h"

void noop_cmd(char **tab, clt_t *client)
{
    if (client->rights <= 0)
        dprintf(client->fd, "530 Login first by using USER and PASS\n");
    else
        dprintf(client->fd, "200 NOOP OK\n");
    (void)tab;
}