/*
** EPITECH PROJECT, 2018
** palindrom.c
** File description:
** luncher for the program
*/

/*!
    \palindrom.c
    \brief file containing loop management of
            EPITECH_Synthesis_2018 Project#2 Palindrome


    \version v1.0
    \author CALVET Alexandre
    \date  Date : 06/14/2019 (mm/dd/yyyy)
*/

#include <stdlib.h>
#include "my.h"
/*!
    \fn void add_param(param_t *set, char **av, int i);
    \brief function use to save the settings (default and given by user)


    \param set {param_t * : struct param_s containing settings (base, nb, imin,
                imax, iteration)}
    \param av {char ** : list of user arguments}
    \param i {int : place of the argument to be saved}
    \return void
*/

void add_param(param_t *set, char **av, int i)
{
    int test = str_to_int(av[i+1]);

    if (my_strcmp(av[i], "-b") == 0) {
        if (test <= 1 || test > 10)
            set->base = -1;
        else
            set->base = test;
        }
    if (my_strcmp(av[i], "-imax") == 0) {
        if (test < 0)
            set->max = -1;
        else
            set->max = test;
    }
    if (my_strcmp(av[i], "-imin") == 0) {
        if (test < 0)
            set->min = -1;
        else
            set->min = test;
    }
}

/*!
    \fn void init_param(param_t *set, char **argv);
    \brief initialize the setting structure for the rest of the program


    \param set {param_t * : struct param_s containing settings (base, nb,
                imin, imax, iteration)}
    \param av {char ** : list of user arguments}
    \return void
*/

void init_param(param_t *set, char **av)
{
    int len = tablen(av);

    set->nb = str_to_int(av[2]);
    if (len < 4)
        return;
    for (int i = 3; av[i] != NULL; i = i + 2) {
        add_param(set, av, i);
    }
}

/*!
    \fn int verif_param(param_t *set);
    \brief function use to check if settings are good


    \param set { param_t * : struct param_s containing settings (base, imin,
                imax, iteration, nb)}
    \return int : OUTPUT the program 0 (SUCCESS) | 84 (ERROR)
*/

int verif_param(param_t *set)
{
    if (set->base == -1 || set->min == -1 || set->max == -1)
        return (ERROR);
    if (set->min > set->max)
        return (ERROR);
    return (SUCCESS);
}

static int check_palin(param_t *set, int nb)
{
    int tmp = nb;
    int sum = 0;

    while (nb > 0) {
        sum = sum * set->base + (nb % set->base);
        nb /= set->base;
    }
    if (sum == tmp) {
        return (SUCCESS);
    }
    return (ERROR);
}

/*!
    \fn int palindrom(char **argv);
    \brief function use to lunch loop for n option or p option


    \param argv {char ** : list of user arguments}
    \return int : OUTPUT the program 0 (SUCCESS) | 84 (ERROR)
*/

int palindrom(char **av)
{
    param_t settings = {.base = 10, .nb = 0, .min = 0, .max = 100, \
    .ite = 0, .status = 0};

    init_param(&settings, av);
    if (verif_param(&settings) == ERROR)
        return (ERROR);
    if (my_strcmp(av[1], "-n") == 0)
        start_iteration_n(&settings, str_to_int(av[2]));
    if (my_strcmp(av[1], "-p") == 0) {
        if (check_palin(&settings, str_to_int(av[2])) == ERROR) {
            my_puterr("invalid argument\n");
            return (ERROR);
        }
        start_iteration_p(&settings);
    }
    return (SUCCESS);
}
