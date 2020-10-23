/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** clt_connection
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "serveur.h"

static clt_t *init_client(srv_t *ftp, char *ip)
{
    clt_t *new = malloc(sizeof(*new));

    if (!new)
        return NULL;
    new->fd = ftp->fd_client;
    new->ip = strdup(ip);
    new->quit = false;
    new->user = NULL;
    new->rights = -1;
    return new;
}

static void handle_entry(clt_t *client, char *entry)
{
    char **tab = NULL;

    if (entry) {
        if (strlen(entry) > 0) {
            tab = str_to_word_array(entry, " \t\n\r");
            if (tab) {
                handle_cmd(tab, client);
                free_array(tab);
            } else
                dprintf(client->fd, "500 cmd not found\n");
        }
        free(entry);
    }
}

static void getipasstring(struct sockaddr_in clt, char *str)
{
    inet_ntop(AF_INET, (struct in_addr *)&clt.sin_addr, str,
        INET_ADDRSTRLEN);
}

static void handle_client(srv_t *ftp, char *ip)
{
    char *line = NULL;
    clt_t *new_client = init_client(ftp, ip);

    if (!new_client)
        return;
    dprintf(new_client->fd, "220 Connected to myftp\n");
    while ((line = my_gnl(ftp->fd_client)) != NULL) {
        handle_entry(new_client, line);
        if (new_client->quit)
            break;
    }
    if (!new_client || new_client->fd == -1)
        return;
    if (new_client->user)
        free(new_client->user);
    if (new_client->ip)
        free(new_client->ip);
    free(new_client);
    return;
}

int srv_loop(srv_t *ftp)
{
    struct sockaddr_in clt;

    for (char *str = calloc(INET_ADDRSTRLEN, sizeof(*str));;) {
        ftp->fd_client = accept(ftp->fd_server, (struct sockaddr *)&clt,
            &ftp->socket);
        if (ftp->fd_client != -1) {
            if (fork() == 0) {
                getipasstring(clt, str);
                printf("\t--- New client from %s\n", str);
                handle_client(ftp, inet_ntoa(clt.sin_addr));
                printf("\t--- Client disconnected: %s\n", str);
                close(ftp->fd_client);
                free(str);
                break;
            } else
                close(ftp->fd_client);
        }
    }
    close(ftp->fd_server);
    return (EXIT_SUCCESS);
}
