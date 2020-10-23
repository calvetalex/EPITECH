/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** menger.c
*/

#include <stdint.h>
#include <stdio.h>
#include "menger.h"
#include "drawing.h"

static uint32_t get_color(int level)
{
    uint8_t tmp = 0xFF / level;
    return (tmp * 256 * 256 + tmp * 256 + tmp);
}

void menger(menger_t data, unsigned int **img)
{
    if (data.level <= 0 || data.x < 0 || data.y < 0 || data.size < 3)
        return;
    data.size /= 3;
    draw_square(img, (point_t){data.x + data.size, data.y + data.size},
        (uint32_t)data.size, get_color(data.level));
    menger((menger_t){data.x, data.y, data.size,
        (data.level - 1)}, img);
    menger((menger_t){data.x + data.size, data.y, data.size,
        (data.level - 1)}, img);
    menger((menger_t){data.x + data.size * 2, data.y, data.size,
        (data.level - 1)}, img);
    menger((menger_t){data.x, data.y + data.size, data.size,
        (data.level - 1)}, img);
    menger((menger_t){data.x + data.size * 2, data.y + data.size, data.size,
        (data.level - 1)}, img);
    menger((menger_t){data.x + data.size * 2, data.y + data.size * 2, data.size,
        (data.level - 1)}, img);
    menger((menger_t){data.x, data.y + data.size * 2, data.size,
        (data.level - 1)}, img);
    menger((menger_t){data.x + data.size, data.y + data.size * 2, data.size,
        (data.level - 1)}, img);
}