/*
** EPITECH PROJECT, 2018
** make_iteration.c
** File description:
** make an iteration
*/

/*!
    \file start.c
    \brief file containing function to make iterations of
            EPITECH_Synthesis_2018 Project#2 Palindrome

    \version v1.0
    \author CALVET Alexandre
    \date  Date : 06/14/2019 (mm/dd/yyyy)
*/

#include "my.h"

/*!
    \fn int make_iteration(param_t *set, int nb);
    \brief function use to make an iteration, first reverse the nbr given
            and then add this reversed nb to the original nb


    \param argc {param_t * : struct param_s settings containing (base, nb,
                iteration, imin, imax)}
    \param nb {int : nb to iterate}
    \return int : OUTPUT the function the nb modified
*/

int make_iteration(param_t *set, int nb)
{
    int tmp = nb;
    int sum = 0;

    while (nb > 0) {
        sum = sum * set->base + (nb % set->base);
        nb /= set->base;
    }
    nb = tmp + sum;
    return (nb);
}
