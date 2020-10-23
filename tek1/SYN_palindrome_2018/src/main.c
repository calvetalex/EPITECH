/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/

/*!
    \file main.c
    \brief file containing main function of
            EPITECH_Synthesis_2018 Project#2 Palindrome

    \version v1.0
    \author CALVET Alexandre
    \date  Date : 06/14/2019 (mm/dd/yyyy)
*/

#include "my.h"

/*!
    \fn int main(int ac, char **av);
    \brief function use to manage call of the differents functions like
            error management and repartiotion of the loops


    \param ac {int : number of user arguments}
    \param av {char ** : list of user arguments}
    \return int : OUTPUT the program 0 (SUCCESS) | 84 (ERROR)
*/

int main(int ac, char **av)
{
    if (argv_handle(ac, av) == ERROR)
        return (ERROR);
    if (palindrom(av) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
