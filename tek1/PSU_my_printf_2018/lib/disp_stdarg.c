/*
** EPITECH PROJECT, 2018
** disp_stdarg.c
** File description:
** disp arg followed by '\n' in the order in which they are given
*/
#include <stdarg.h>
#include "../include/my.h"

void disp_stdarg(char s, va_list *ap)
{
    if (s == 'd')  {
        my_put_nbr(va_arg(*ap, int));
    }
    if (s == 'c')
        my_putchar(va_arg(*ap, int));
    if (s == 's')
        my_putstr(va_arg(*ap, char *));
}
