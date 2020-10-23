/*
** EPITECH PROJECT, 2018
** starting_p.c
** File description:
** iteration for p flags
*/

/*!
    \file starting_p.c
    \brief file containing loop for p option of
            EPITECH_Synthesis_2018 Project#2 Palindrome

    \version v1.0
    \author CALVET Alexandre
    \date  Date : 06/14/2019 (mm/dd/yyyy)
*/

#include "my.h"

/*!
    \fn void test_variable(param_t *set, int tmp, int nb);
    \brief make iteration for a nbr and test if it could be a
            n_palindromic nbr given by the user


    \param set {param_t * : struct param_s containing settings
                    (base, iteration, imin, imax...)}
    \param tmp {int : nbr to iterate and test}
    \param nb {int : nbr to find}
    \return void
*/

void test_variable(param_t *set, int tmp, int nb)
{
    while (tmp > 0) {
        if (set->ite >= set->min && tmp == set->nb) {
            my_putstr(putnbr(nb)+ " leads to ");
            my_putstr(putnbr(set->nb) + " in ");
            my_putstr(putnbr(set->ite) + " iteration(s) in base ");
            my_putstr(putnbr(set->base) + "\n");
            set->status++;
            break;
        }
        tmp = make_iteration(set, tmp);
        set->ite++;
        if (set->ite > set->max) {
            break;
        }
    }
}

/*!
    \fn int start_iteration(param_t *set);
    \brief loop for p option
            make iterations for 0 to the nbr given


    \param set {param_t * : struct param_s containing settings (base, nb,
                iteration, imin, imax)}
    \return int : OUTPUT the program 0 (SUCCESS)
*/

int start_iteration_p(param_t *set)
{
    int tmp = 0;

    for (int nb = 0; nb <= set->nb; nb++) {
        tmp = nb;
        test_variable(set, tmp, nb);
        set->ite = 0;
    }
    if (set->status == 0)
        my_putstr("no solution\n");
    return (SUCCESS);
}
