/*
** EPITECH PROJECT, 2020
** menger
** File description:
** main function
*/

#include <stdio.h>
#include <string.h>
#include "./menger.h"

int main(int ac, char **av)
{
    if (ac != 3) {
        fprintf(stderr, "Use ./menger [square size] [number of lvl]\n");
        return (EXIT_ERROR);
    }
    if (strlen(av[1]) == 0 || strlen(av[2]) == 0) {
        fprintf(stderr, "ERROR: argument can't be blank\n");
        return (EXIT_ERROR);
    }
    if (menger(av) != 0) {
        return (EXIT_ERROR);
    }
    return (EXIT_SUCCESS);
}