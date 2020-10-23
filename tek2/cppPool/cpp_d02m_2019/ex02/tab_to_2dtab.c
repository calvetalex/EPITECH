/*
** EPITECH PROJECT, 2020
** tab to 2D tab
** File description:
** place tab into a 2D tab
*/

#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    if (!(*res = malloc(sizeof(int*) * length + 1)))
        return;
    for (int i = 0; i <= length; i++) {
        if (!((*res)[i] = malloc(sizeof(int) * width + 1)))
            return;
        for (int j = 0; j <= width; j++) {
            (*res)[i][j] = tab[i * width + j];
        }
    }
}