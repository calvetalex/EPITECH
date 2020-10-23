/*
** EPITECH PROJECT, 2018
** disp_oct.c
** File description:
** disp a nb in (8)
*/
#include "../include/my.h"

void disp_oct(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb*= -1;
    }
    if (nb >= 8)
        disp_oct(nb / 8);
    my_putchar((nb % 8) + '0');
}
