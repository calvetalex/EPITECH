/*
** EPITECH PROJECT, 2020
** drawing
** File description:
** header file
*/

#ifndef DRAWING_H_
#define DRAWING_H_

#include <stdint.h>
#include <stddef.h>

typedef struct point_s {
    uint32_t x;
    uint32_t y;
} point_t;

void  draw_square(uint32_t  **img, const  point_t *origin, size_t  size,
    uint32_t  color);

#endif /* !DRAWING_H_ */
