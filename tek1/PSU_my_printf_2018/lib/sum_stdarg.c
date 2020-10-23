/*
** EPITECH PROJECT, 2018
** sum_stdarg.c
** File description:
** if i=0 (return sum of nb last arg) else if i=1 (return len of last nb str)
*/
#include <stdarg.h>
#include "../include/my.h"

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    int res = 0;

    va_start(ap, nb);
    if (i == 0)
        for (int j = 0; j < nb; j++) {
            res += va_arg(ap, int);
        }
    else if (i == 1)
        for (int k = 0; k < nb; k++) {
            res += my_strlen(va_arg(ap, char *));
        }
    else
        return (84);
    va_end(ap);
    return (res);
}
