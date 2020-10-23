/*
** EPITECH PROJECT, 2018
** argv_handle.c
** File description:
** error handling for argv given
*/

/*!
    \argv_handle.c
    \brief file containing error handling functions of
            EPITECH_Synthesis_2018 Project#2 Palindrome

    File containing main function of the project,
    needed to manage call the others functions


    \version v1.0
    \author CALVET Alexandre
    \date  Date : 06/14/2019 (mm/dd/yyyy)
*/

#include "my.h"

#include <stdlib.h>

/*!
    \fn static void disp_help(void)
    \brief function which display help to make the program
            undestandable by everyone

    \param argc {void}
    \return int : EXIT the program 0 (SUCCESS)
*/

static void disp_help(void)
{
    my_putstr("USAGE\n\t./palindrome -n number -p palindrome [-b base] \
[-imin i] [-imax i]\n");
    my_putstr("DESCRIPTION:\n");
    my_putstr("\t-n n\t\tinteger to be transformed (>=0)\n\t");
    my_putstr("-p pal\t\tpalindromic number to be obtained (incompatible \
with the -n option) (>=0)\n\t\t\tif defined, all fitting values will be \
output\n");
    my_putstr("\t-b base\t\tbase in wich the procedure will be executed \
(1<b<=10) [def: 10]\n");
    my_putstr("\t-imin i\t\tminimum number of iteration, included (>=0) \
[def: 0]\n");
    my_putstr("\t-imax i\t\tmaximum number of interation, included (>=0) \
[def: 100]\n");
    exit(SUCCESS);
}

/*!
    \fn static int check_flags(int ac, char **av);
    \brief function use to verify each flag option when the program start


    \param ac {int : number of user arguments}
    \param av {char ** : list of user arguments}
    \return int : OUTPUT the program 0 (SUCCESS) | 84 (ERROR)
*/

static int check_flags(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        disp_help();
    if (ac % 2 != 1)
        return (ERROR);
    if (my_strcmp(av[1], "-n") != 0 && my_strcmp(av[1], "-p") != 0)
        return (ERROR);
    if (ac > 3)
        for (int i = 3; av[i] != NULL; i = i + 2) {
            if (my_strcmp(av[i], "-b") != 0 && my_strcmp(av[i], "-imin") != 0 \
            && my_strcmp(av[i], "-imax") != 0 && (my_strcmp(av[i], "-n") == 0 \
            || my_strcmp(av[i], "-p") == 0))
                return (ERROR);
        }
    if (my_str_isnum(av[2]) != 0)
        return (ERROR);
    for (int i = 2; av[i+1] != NULL; i = i+2)
        if (my_str_isnum(av[i]) != 0)
            return (ERROR);
    return (SUCCESS);
}

/*!
    \fn int argv_handle(int argc, char **argv);
    \brief function use to manage call of error management functions,
            user arguments picking and the functional program


    \param argc {int : number of user arguments}
    \param argv {char ** : list of user arguments}
    \return int : OUTPUT the program 0 (SUCCESS) | 84 (ERROR)
*/

int argv_handle(int ac, char **av)
{
    if (ac < 2) {
        my_puterr("invalid argument\n");
        return (ERROR);
    }
    if (check_flags(ac, av) == ERROR) {
        my_puterr("invalid argument\n");
        return (ERROR);
    }
    return (SUCCESS);
}
