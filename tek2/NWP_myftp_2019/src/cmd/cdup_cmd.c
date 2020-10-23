/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** cdup_cmd
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "serveur.h"

void cdup_cmd(char **tab, clt_t *client)
{
    if (client->rights <= 0)
        dprintf(client->fd, "530 Login first by using USER and PASS\n");
    else if (chdir("../") != 1)
        dprintf(client->fd, "200 Directory was changed successfully\n");
    else
        dprintf(client->fd, "550 can't change current directory\n");
    (void)tab;
}