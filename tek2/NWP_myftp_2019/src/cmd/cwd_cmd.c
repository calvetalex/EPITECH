/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** cwd_cmd
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "serveur.h"

void cwd_cmd(char **tab, clt_t *client)
{
    if (client->rights <= 0)
        dprintf(client->fd, "530 Login first by using USER and PASS\n");
    else if (tab[1] && chdir(tab[1]) != -1)
        dprintf(client->fd, "250 Directory was changed successfully\n");
    else
        dprintf(client->fd, "550 can't change current directory\n");
}