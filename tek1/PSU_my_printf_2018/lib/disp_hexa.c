/*
** EPITECH PROJECT, 2018
** disp_hexa.c
** File description:
** disp in nb in (16)
*/
#include "../include/my.h"

void disp_hexamin(int nb)
{
    if (nb < 0)
        nb *= -1;
    if (nb >= 16)
        disp_hexamin((nb / 16));
    if ((nb % 16) >= 10)
        my_putchar((nb % 16)- 10 + 'a');
    else
        my_putchar((nb % 16) + '0');
}

void disp_hexamaj(int nb)
{
    if (nb < 0)
        nb*= -1;
    if (nb >= 16)
        disp_hexamaj((nb / 16));
    if ((nb % 16) >= 10)
        my_putchar((nb % 16) - 10 + 'A');
    else
        my_putchar((nb % 16) + '0');
}
