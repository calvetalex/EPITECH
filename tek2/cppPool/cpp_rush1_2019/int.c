/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 03
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "new.h"
#include "int.h"
#include "raise.h"

typedef struct
{
    Class base;
    int value;
}IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        raise("Object must be allocated!");
    this->value = (int) va_arg(*args, int);
    return;
}

static void Int_dtor(IntClass *this)
{
    if (!this)
        raise("Int must be allocated!");
    return;
}

static char *Int_str(IntClass *this)
{
    char *str = NULL;

    if (!this)
        raise("Value must be initialize!");
    asprintf(&str, "<Int (%d)>", this->value);
    return (str);
}

static IntClass *Int_add(IntClass *a, IntClass *b)
{
    IntClass *res = new(Int);

    res->value = a->value + b->value;
    return (res);
}

static IntClass *Int_sub(IntClass *a, IntClass *b)
{
    IntClass *res = new(Int);

    res->value = a->value - b->value;
    return (res);
}

static IntClass *Int_mul(IntClass *p1, IntClass *p2)
{
    IntClass *res = new(Int);

    res->value = p1->value * p2->value;
    return (res);
}

static IntClass *Int_div(IntClass *p1, IntClass *p2)
{
    IntClass *res = new(Int);

    if (p2->value == 0)
        raise("Division by Zero");
    res->value = p1->value / p2->value;
    return (res);
}

static bool Int_eq(IntClass *p1, IntClass *p2)
{
    if (p1->value == p2->value)
        return (true);
    else
        return (false);
}

static bool Int_lt(IntClass *p1, IntClass *p2)
{
    if (p1->value < p2->value)
        return (true);
    else
        return (false);
}

static bool Int_gt(IntClass *p1, IntClass *p2)
{
    if (p1->value > p2->value)
        return (true);
    else
        return (false);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .value = 0,
};

const Class *Int = (Class *)&_description;
