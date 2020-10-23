/*
** EPITECH PROJECT, 2020
** foo
** File description:
** foo structur
*/

#ifndef FOO_H_
#define FOO_H_

#include <stdint.h>

typedef union bar_u
{
    int16_t foo;
    int16_t bar;
} bar_t;

typedef struct foo_s
{
    int16_t foo;
    bar_t bar;
} foo_2_t;

typedef union foo_u
{
    int32_t bar;
    foo_2_t foo;
} foo_t;

#endif /* !EX05_H_ */
