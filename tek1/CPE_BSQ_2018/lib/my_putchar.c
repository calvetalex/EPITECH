/*
** EPITECH PROJECT, 2018
** mu_putchar.c
** File description:
** write a char on the standar output
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1 , &c , 1);
    return (0);
}