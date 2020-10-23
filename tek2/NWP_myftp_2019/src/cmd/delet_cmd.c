/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** delet_cmd
*/

#include <stdio.h>
#include <string.h>
#include "serveur.h"

void delet_cmd(char **tab, clt_t *client)
{
    if (client->rights <= 0)
        dprintf(client->fd, "530 Login first by using USER and PASS\n");
    else if (tab[1] && remove(tab[1]) == 0)
        dprintf(client->fd, "250 file deleted\n");
    else
        dprintf(client->fd, "550 file not found\n");
}