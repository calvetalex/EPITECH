/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** help_cmd
*/

#include <stdio.h>
#include <string.h>
#include "serveur.h"

static const map_cmd_t cmds[] = {
    {"CDUP", "CDUP\nChange working directory to parent directory\n"},
    {"CWD", "CWD path\nChange working directory\n"},
    {"DELE", "DELE file\n"},
    {"HELP",
    "HELP [cmd]\nif cmd, display help for this one else list all cmds\n"},
    {"NOOP", "NOOP\nNO Operation\n"},
    {"PASS", "PASS psswd\nSpecify password for authentification\n"},
    {"PWD", "PWD\nPrint working directory\n"},
    {"QUIT", "QUIT\nDisconnection\n"},
    {"USER", "USER username\nSpecify username for authentification\n"},
    {"LIST", "LIST [dir]\nlist files in the directory (default ./)\n"},
    {NULL, NULL}
};

static int len_array(char **tab)
{
    int i = 0;

    for (i = 0; tab[i] != NULL; i++);
    return (i);
}

static int help_one(int fd, char **tab)
{
    int i = 0;

    for (i = 0; cmds[i].key != NULL; i++)
        if (strcmp(cmds[i].key, tab[1]) == 0)
            break;
    if (i > 8) {
        dprintf(fd, "503 Command not found. Please try HELP\n");
        return 1;
    } else
        dprintf(fd, "214 - %s", cmds[i].value);
    return 0;
}

static void help_all(int fd)
{
    dprintf(fd, "214 FTP-The following commands are recognized:\
    \n\tUSER\n\tPASS\n\tQUIT\n\tHELP\n\tCDUP\n\tCWD\n\tDELE\
    \n\tNOOP\n\tPWD\n");

}

void help_cmd(char **tab, clt_t *client)
{
    int err = 0;

    if (len_array(tab) == 2)
        err = help_one(client->fd, tab);
    else
        help_all(client->fd);
    if (err == 0)
        dprintf(client->fd, "214 - HELP DONE\n");
}