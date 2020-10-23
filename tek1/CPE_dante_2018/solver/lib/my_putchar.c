/*
** EPITECH PROJECT, 2018
** mu_putchar.c
** File description:
** write a char on the standar output
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1 , &c , 1);
}
