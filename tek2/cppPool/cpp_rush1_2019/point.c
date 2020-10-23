/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "new.h"
#include "point.h"
#include "raise.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        raise("Object must be allocated!");
    this->x = va_arg(*args, int32_t);
    this->y = va_arg(*args, int32_t);
    return;
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *Point_str(PointClass *this)
{
    char *str = NULL;

    if (!this)
        raise("Value must be initialize!");
    asprintf(&str, "<Point (%d, %d)>", this->x, this->y);
    return (str);
}

PointClass *Point_add(PointClass *a, PointClass *b)
{
    PointClass *res = new(Point);

    res->x = a->x + b->x;
    res->y = a->y + b->y;
    return (res);
}

PointClass *Point_sub(PointClass *a, PointClass *b)
{
    PointClass *res = new(Point);

    res->x = a->x - b->x;
    res->y = a->y - b->y;
    return (res);
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (Class *)&_description;