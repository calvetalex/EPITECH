/*
** EPITECH PROJECT, 2018
** rush3.c
** File description:
** testing
*/
#include "include/my.h"
#include <unistd.h>

void diag_letter(char *buff, int large, int high, int i)
{
    if (buff[i - 2] == 'C') {
        my_putstr("[rush1-4] ");
        my_put_nbr(large);
        my_putchar(' ');
        my_put_nbr(high);
    } else if (buff[i - 2] == 'A') {
        my_putstr("[rush1-5] ");
        my_put_nbr(large);
        my_putchar(' ');
        my_put_nbr(high);
    }
}

void case_b(char *buff,int large, int high)
{
    my_putstr("[rush1-3] ");
    my_put_nbr(large);
    my_putchar(' ');
    my_put_nbr(high);
    my_putstr(" || [rush1-4] ");
    my_put_nbr(large);
    my_putchar(' ');
    my_put_nbr(high);
    my_putstr(" || [rush1-5] ");
    my_put_nbr(large);
    my_putchar(' ');
    my_put_nbr(high);
}

void check_letter(char *buff, int large, int high)
{
    int i = 1;

    if (buff[0] == 'B')
        case_b(buff, large, high);
    while (buff[i] != '\n') {
        i++;
    }
    if (buff[i - 1] == 'A') {
        my_putstr("[rush1-3] ");
        my_put_nbr(large);
        my_putchar(' ');
        my_put_nbr(high);
    } else {
        while (buff[i] != '\0')
            i++;
        diag_letter(buff, large, high, i);
    }
}

void check_char(char *buff, int large, int high)
{
    if (buff[0] == '*' || buff[0] == '/') {
        my_putstr("[rush1-2] ");
        my_put_nbr(large);
        my_putchar(' ');
        my_put_nbr(high);
    }
    if (buff[0] == 'o') {
        my_putstr("[rush1-1] ");
        my_put_nbr(large);
        my_putchar(' ');
        my_put_nbr(high);
    }
}

void rush3(char *buff)
{
    int large = 0;
    int high = 0;
    int i = 0;

    while (buff[i] != '\n') {
        large++;
        i++;
    }
    while (buff[i] != '\0') {
        if (buff[i] == '\n')
            high++;
        i++;
    }
    if (buff[0] == 'A' || buff[0] == 'B' || buff[0] == 'C')
        check_letter(buff, large, high);
    else if (buff[0] == '*' || buff[0] == '/' || buff[0] == 'o')
        check_char(buff, large, high);
    else
        my_putstr("none");
    my_putchar('\n');
}
