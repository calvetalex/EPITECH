/*
** EPITECH PROJECT, 2018
** disp_binary.c
** File description:
** display a nb in (2)
*/
#include "../include/my.h"
#include <stdarg.h>

void disp_binary(long int nb)
{
    if (nb < 0) {
        my_putchar('1');
        nb *= -1;
    }
    if (nb >= 2)
        disp_binary((nb / 2));
    my_putchar(((nb % 2 ) + '0'));
}
