/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** display a number
*/
#include "../include/my.h"

void my_put_nbr(int nb)
{
    long int nbr = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10)
        my_put_nbr((nb/10));
    nbr = nb % 10 + '0';
    my_putchar(nbr);
}
