/*
** EPITECH PROJECT, 2018
** disp_nonprintable.c
** File description:
** disp in (8) non printable char
*/

#include "../include/my.h"

#include <stdlib.h>

int disp_zero(int nb, int *i)
{
    if(nb > 8)
        disp_zero((nb / 8), i);
    *i += 1;
}

void have_octa(int nb)
{
        if (nb > 8) {
            have_octa((nb / 8));
        }
        my_putchar((nb % 8) + '0');
}

void display_octa(char str)
{
    int nb = (int) str;
    int i = 0;
    int *j = &i;
    int res = 0;

    disp_zero(nb, j);
    res = 3 - i;
    while (res != 0) {
        my_putchar('0');
        res--;
    }
    have_octa(nb);
}

void disp_nonprintable(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            display_octa(str[i]);
        }
    }
}
