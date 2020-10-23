/*
** EPITECH PROJECT, 2018
** checking_palindrome.c
** File description:
** checking if a number is a palindrome
*/

/*!
    \file checking_palindrom.c
    \brief file containing function to check palindromic nbr of
            EPITECH_Synthesis_2018 Project#2 Palindrome

    \version v1.0
    \author CALVET Alexandre
    \date  Date : 06/14/2019 (mm/dd/yyyy)
*/

#include "my.h"
/*!
    \fn int check_palindrome_n(param_t *set, int nb);
    \brief function use to check if a nb is a palindrom in a base X for n option


    \param set {param_t * : struct param_s containing settings (base, imin,
                imax, nb, iteration) }
    \param nb {int : nbr to test}
    \return int : OUTPUT the program 0 (SUCCESS) | 84 (ERROR)
*/

int check_palindrome_n(param_t *set, int nb)
{
    int tmp = nb;
    int sum = 0;

    while (nb > 0) {
        sum = sum * set->base + (nb % set->base);
        nb /= set->base;
    }
    if (sum == tmp) {
        my_putstr(putnbr(set->nb) + " leads to ");
        my_putstr(putnbr(sum) + " in ");
        my_putstr(putnbr(set->ite) + " iteration(s) in base ");
        my_putstr(putnbr(set->base) + "\n");
        return (SUCCESS);
    }
    return (ERROR);
}
