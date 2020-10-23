/*
** EPITECH PROJECT, 2018
** disp_unsigned.c
** File description:
** disp_unsigned_int
*/

#include "../include/my.h"

void disp_unsigned(unsigned int nb)
{
    if (nb > 10)
        disp_unsigned(nb / 10);
    my_putchar((nb % 10) + '0');
}
