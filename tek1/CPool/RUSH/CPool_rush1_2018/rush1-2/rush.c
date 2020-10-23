/*
** EPITECH PROJECT, 2018
** rush.c
** File description:
** square
*/

#include <unistd.h>

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

void check_three(int start, int x, int a)
{
    if (start == x) {
        my_putchar(92);
        while (a > 0) {
            my_putchar('*');
            a = a - 1;
        }
        my_putstr("/\n");
    }
}

void check_up(int x, int y)
{
    if (x == 1) {
        while (y > 0) {
            my_putstr("*\n");
               y = y - 1;
        }
    } else if (y == 1) {
        while (x > 0) {
            my_putchar('*');
            x = x - 1;
            if (x == 0)
                my_putchar('\n');
        }
    } else if (x == 2 && y == 1)
        my_putstr("**\n");
}

void check_two(int x, int y, int end, int start)
{
    int a = x - 2;
    int j = 0;
    int o = y - 2;

    while (end < o) {
        my_putchar('*');
        while (j < a) {
            my_putchar(' ');
            j = j + 1;
        }
        j = 0;
        my_putstr("*\n");
        end = end + 1;
    }
    check_three(start, x, a);
}

int rush(int x, int y)
{
    int a = x - 2;
    int start = x;
    int end;
    int j;

    if (x <= 0 || y <= 0)
        my_putstr("Invalid size\n");
    check_up(x, y);
    if (x > 1 && y > 1) {
        if (start == x) {
            my_putchar('/');
            while (a > 0) {
                my_putchar('*');
                a = a - 1;
            }
            my_putchar(92);
            my_putstr("\n");
        }
        check_two(x, y, end, start);
    }
}
