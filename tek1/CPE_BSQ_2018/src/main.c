/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/

#include <stdlib.h>
#include "my.h"

int main(int ac, char **av)
{
    char *file = NULL;
    game_t info;
    int err = 0;

    err = verif_input(ac, av);
    if (err == ERROR) {
        my_puterr("ERROR: try ./bsq -h.\n");
        return (ERROR);
    }
    file = my_strdup(av[1]);
    init_game(&info, file);
    find_bsq(&info);
    free_all(&info, file);
    return (SUCCESS);
}