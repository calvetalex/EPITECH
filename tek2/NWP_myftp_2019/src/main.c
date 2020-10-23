/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include "serveur.h"

static void help(void)
{
    printf("USAGE:\n\t./myftp port path\n");
    printf("DESCRIPTION:\n");
    printf("\tport\tthe port number on which the server socket listens\n");
    printf("\tpath\tthe path to the home directory for the Anonymous user\n");
}

static srv_t *get_data(srv_t *ftp, char *port, char *path)
{
    ftp->pr_e = getprotobyname("TCP");
    ftp->path = path;
    ftp->port = atoi(port);
    ftp->fd_server = socket(AF_INET, SOCK_STREAM, ftp->pr_e->p_proto);
    if (ftp->fd_server == -1)
        return NULL;
    ftp->socket = sizeof(ftp->socket_in);
    ftp->socket_in.sin_family = AF_INET;
    ftp->socket_in.sin_port = htons(ftp->port);
    ftp->socket_in.sin_addr.s_addr = INADDR_ANY;
    return ftp;
}

static int init_srv(srv_t *ftp, char *port, char *path)
{
    if (chdir(path) == -1) {
        fprintf(stderr, "ERROR: bad path given.\n");
        return (EXIT_FAILURE);
    }
    if (!(ftp = get_data(ftp, port, path)))
        return (EXIT_FAILURE);
    if (bind(ftp->fd_server, (const struct sockaddr *)&ftp->socket_in,
        sizeof(ftp->socket_in)) == -1) {
        shutdown(ftp->fd_server, SHUT_WR);
        return (EXIT_FAILURE);
    }
    if (listen(ftp->fd_server, 50) == -1)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    srv_t *myftp = malloc(sizeof(*myftp));

    if (!myftp)
        return (84);
    if (ac != 3) {
        free(myftp);
        help();
        if (ac == 2 && strcmp(av[1], "-h") == 0)
            return (EXIT_SUCCESS);
        return (84);
    } else {
        if (init_srv(myftp, av[1], av[2]) == EXIT_FAILURE) {
            free(myftp);
            return (84);
        }
        printf("FTP v0.0.1\nSERVER OPEN...\n");
        srv_loop(myftp);
        shutdown(myftp->fd_server, SHUT_WR);
        free(myftp);
    }
    return (EXIT_SUCCESS);
}