/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** serveur.h
*/

#ifndef SERVEUR_H_
#define SERVEUR_H_

#include <arpa/inet.h>
#include <stdbool.h>

typedef struct s_server {
    int fd_server;
    int fd_client;
    int port;
    char *path;
    struct protoent *pr_e;
    struct sockaddr_in socket_in;
    socklen_t socket;
} srv_t;

typedef struct s_client {
    int fd;
    char *ip;
    char *user;
    bool quit;
    int rights;
} clt_t;

typedef struct s_map_cmd {
    char *key;
    char *value;
} map_cmd_t;

/*
** FTP
*/
int srv_loop(srv_t *);
void handle_cmd(char **, clt_t *);
char *my_gnl(int);

/*
** TOOLS
*/
char **str_to_word_array(char *, char *);
void free_array(char **);

/*
** CMD
*/
void help_cmd(char **, clt_t *);
void user_cmd(char **, clt_t *);
void pass_cmd(char **, clt_t *);
void quit_cmd(char **, clt_t *);
void cdup_cmd(char **, clt_t *);
void cwd_cmd(char **, clt_t *);
void pwd_cmd(char **, clt_t *);
void delet_cmd(char **, clt_t *);
void noop_cmd(char **, clt_t *);
void list_cmd(char **tab, clt_t *client);


#endif /* !SERVER_H_ */