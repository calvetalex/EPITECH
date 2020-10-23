/*
** EPITECH PROJECT, 2018
** my_random.c
** File description:
** generate a random nb
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int my_random(int n)
{
    time_t t;

    srand((unsigned) time(&t));
    return (rand() % n);
}