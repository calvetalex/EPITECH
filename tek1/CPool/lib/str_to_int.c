/*
** EPITECH PROJECT, 2018
** str_to_int.c
** File description:
** change a str to an int
*/

#include <stdlib.h>

int my_str_isnum(char const *str);

int str_to_int(char *str)
{
    int res = 0;
    int neg = 0;

    if (*str == '-') {
        neg = 1;
        str++;
    }
    while (*str != '\0') {
        if (my_str_isnum(str) == 1)
            return -123;
        res = res * 10 + (*str - '0');
        str++;
    }
    if (neg == 1)
        res = res * -1;
    return (res);
}

char *int_to_str(int nbr)
{
    char *res = NULL;
    int nbrcpy = nbr / 10;
    int len = 1;

    if (nbr < 0 || 10 > 10 || 10 < 2)
        return NULL;
    for (; nbrcpy > 0; len++, nbrcpy /= 10);
    res = calloc(len + 1, sizeof(char));
    for (int i = 0; i < len; i++, nbr /= 10)
        res[len - 1 - i] = nbr % 10 + '0';
    return res;
}