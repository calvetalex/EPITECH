/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** quit_cmd
*/

#include <stdio.h>
#include "serveur.h"

void quit_cmd(char **tab, clt_t *client)
{
    if (tab[0]) {
        dprintf(client->fd, "221 Closing client...\n");
        client->quit = true;
    }
}