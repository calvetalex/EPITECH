/*
** EPITECH PROJECT, 2020
** drawing
** File description:
** function to draw a square
*/

#include "drawing.h"

void  draw_square(uint32_t **img, const point_t *origin, size_t size,
    uint32_t color)
{
    for (uint32_t i = origin->y; i < origin->y + size; ++i)
        for (uint32_t j = origin->x; j < origin->x + size; ++j)
            img[i][j] = color;
}