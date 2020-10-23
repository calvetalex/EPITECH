/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** list_cmd
*/

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include "serveur.h"

static void print_directory(clt_t *client, char *path)
{
    FILE *dir;
    char *command = NULL;
    char c = 0;

    dprintf(client->fd, "150 File status okay. Opening data connection...\n");
    dprintf(client->fd, "226 Requested file action successful!\n");
    if (asprintf(&command, "ls -l %s", path) == -1) {
            dprintf(client->fd, "451 Requested action aborted\n");
            return;
    }
    if (!(dir = popen(command, "r"))) {
        dprintf(client->fd, "451 Request action aborted: local error\n");
        perror("popen failed()");
        return;
    }
    while (fread(&c, sizeof(char), 1, dir))
        dprintf(client->fd, "%c", c);
    pclose(dir);
}

void list_cmd(char **tab, clt_t *client)
{
    if (client->rights <= 0) {
        dprintf(client->fd, "530 Login first by using USER and PASS\n");
        return;
    }
    print_directory(client, tab[1] ? tab[1] : ".");
    dprintf(client->fd, "226 Closing data connection.\n");

}
