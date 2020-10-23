/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 04
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "new.h"
#include "float.h"
#include "raise.h"

typedef struct
{
    Class   base;
    float     value;
}FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("Object must be allocated!");
    this->value = va_arg(*args, double);
    return;
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *Float_str(FloatClass *this)
{
    char *str = NULL;

    if (!this)
        raise("Value must be initialize!");
    asprintf(&str, "<Float (%f)>", this->value);
    return (str);
}

static FloatClass *Float_add(FloatClass *a, FloatClass *b)
{
    FloatClass *res = new(Float);

    res->value = a->value + b->value;
    return (res);
}

static FloatClass *Float_sub(FloatClass *a, FloatClass *b)
{
    FloatClass *res = new(Float);

    res->value = a->value - b->value;
    return (res);
}

static FloatClass *Float_mul(FloatClass *p1, FloatClass *p2)
{
    FloatClass *res = new(Float);

    res->value = p1->value * p2->value;
    return (res);
}

static FloatClass *Float_div(FloatClass *p1, FloatClass *p2)
{
    FloatClass *res = new(Float);

    if (p2->value == 0)
        raise("Division by Zero");
    res->value = p1->value / p2->value;
    return (res);
}

static bool Float_eq(FloatClass *p1, FloatClass *p2)
{
    if (p1->value == p2->value)
        return (true);
    else
        return (false);
}

static bool Float_lt(FloatClass *p1, FloatClass *p2)
{
    if (p1->value < p2->value)
        return (true);
    else
        return (false);
}

static bool Float_gt(FloatClass *p1, FloatClass *p2)
{
    if (p1->value > p2->value)
        return (true);
    else
        return (false);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .value = 0,
};

const Class *Float = (Class *)&_description;
