/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** display content of an array of words
*/

#include "../include/my.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    for (i = 0; tab[i] != 0; i++){
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
