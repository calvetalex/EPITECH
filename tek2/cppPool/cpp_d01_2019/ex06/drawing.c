/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** drawing.h
*/

#include <stdint.h>
#include <stddef.h>
#include "drawing.h"

void draw_square(uint32_t **img, const point_t origin,
    size_t size, uint32_t color)
{
    for (uint32_t i = origin.y; i < origin.y + size; ++i)
        for (uint32_t j = origin.x; j < origin.x + size; ++j)
            img[i][j] = color;
}