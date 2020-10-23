/*
** EPITECH PROJECT, 2018
** disp_membase.c
** File description:
** disp an adress
*/

#include "../include/my.h"
#include <stdlib.h>

void disp_mem(long unsigned int mem)
{
    if (mem >= 16)
        disp_mem((mem / 16));
    if ((mem % 16) >= 10)
        my_putchar((mem % 16) - 10 + 'a');
    else
        my_putchar((mem % 16) + '0');
}

void disp_membase(long unsigned int ap)
{
    long unsigned int *mem= &ap;

    disp_mem(*mem);
}
