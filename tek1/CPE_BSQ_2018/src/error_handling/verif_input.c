/*
** EPITECH PROJECT, 2018
** verif_input.c
** File description:
** verif if the input is good
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

static void disp_help(void)
{
    my_putstr("USAGE:\n\t./bsq file\n");
    my_putstr("\nDESCRIPTION:\n\tfile\tpath to a map config file\n");
    my_putstr("\nCONFIG FILE:\n\tFirst line\tmust be the nb of line \
in the file\n");
    my_putstr("\tMap\t\tmust be a square with walls and spaces\n");
    my_putstr("\tWall\t\tmust be represented by a 'o'\n");
    my_putstr("\tSpace\t\tmust be represented by a '.'\n");
}

int verif_file(char *file)
{
    int fd = 0;

    if (file == NULL)
        return (ERROR);
    if ((fd = open(file, O_RDONLY)) == -1)
        return (ERROR);
    close(fd);
    return (SUCCESS);
}

int verif_input(int ac, char **av)
{
    int err = 0;

    if (ac != 2)
        return (ERROR);
    if (my_strcmp(av[1], "-h") == 0) {
        disp_help();
        return (SUCCESS);
    }
    err = verif_file(av[1]);
    if (err == SUCCESS)
        return (SUCCESS);
    else
        return (ERROR);
}