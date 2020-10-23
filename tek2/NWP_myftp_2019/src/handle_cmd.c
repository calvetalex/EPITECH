/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** handle_cmd
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serveur.h"

static void exec_cmd(char **tab, clt_t *client, int idx)
{
    void (*function[10])(char **tab, clt_t *client) =
        {&help_cmd, &user_cmd, &pass_cmd, &quit_cmd, &cdup_cmd, &cwd_cmd,
        &pwd_cmd, &delet_cmd, &noop_cmd, &list_cmd};
    (*function[idx])(tab, client);
}

static int search_cmd(char **tab, clt_t *client)
{
    const char *function[11] = {"HELP", "USER", "PASS", "QUIT", "CDUP",
        "CWD", "PWD", "DELE", "NOOP", "LIST", NULL};

    for (int i = 0; function[i] != NULL; i++)
        if (strcasecmp(tab[0], function[i]) == 0) {
            exec_cmd(tab, client, i);
            return (EXIT_SUCCESS);
        }
    return (EXIT_FAILURE);
}

void handle_cmd(char **tab, clt_t *client)
{
    if (!tab) {
        dprintf(client->fd, "500 cmd not found\n");
        return;
    }
    if (search_cmd(tab, client) == EXIT_FAILURE)
        dprintf(client->fd, "500 cmd not found\n");
    return;
}