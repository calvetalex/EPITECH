/*
** EPITECH PROJECT, 2018
** starting_n.c
** File description:
** iteration for n flags
*/

/*!
    \file starting_n.c
    \brief file containing loop for n option of
            EPITECH_Synthesis_2018 Project#2 Palindrome

    \version v1.0
    \author CALVET Aleandre
    \date  Date : 06/14/2019 (mm/dd/yyyy)
*/

#include "my.h"

/*!
    \fn int start_iteration_n(param_t *set, int nb);
    \brief loop of iteration when the user chose the flag n
            call functions to check palindrome and to make iteration


    \param set {param_t * : struct param_s containing settings (base, nb,
                iteration, imin, imax...)}
    \param nb {int : number to test and iterate}
    \return int : OUTPUT the function 0 (SUCCESS)
*/

int start_iteration_n(param_t *set, int nb)
{
    while (set->ite <= set->max) {
        if (set->ite >= set->min && check_palindrome_n(set, nb) == SUCCESS)
            return (SUCCESS);
        nb = make_iteration(set, nb);
        set->ite++;
        if (set->ite > set->max) {
            break;
        }
    }
    my_putstr("no solution\n");
    return (SUCCESS);
}
