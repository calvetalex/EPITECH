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
#include "char.h"
#include "raise.h"

typedef struct
{
    Class   base;
    char   value;
}CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("Object must be allocated!");
    this->value = va_arg(*args, int);
    return;
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_str(CharClass *this)
{
    char *str = NULL;

    if (!this)
        raise("Value must be initialize!");
    asprintf(&str, "<Char (%c)>", this->value);
    return (str);
}

static CharClass *Char_add(CharClass *a, CharClass *b)
{
    CharClass *res = new(Char);

    res->value = a->value + b->value;
    return (res);
}

static CharClass *Char_sub(CharClass *a, CharClass *b)
{
    CharClass *res = new(Char);

    res->value = a->value - b->value;
    return (res);
}

static CharClass *Char_mul(CharClass *p1, CharClass *p2)
{
    CharClass *res = new(Char);

    res->value = p1->value * p2->value;
    return (res);
}

static CharClass *Char_div(CharClass *p1, CharClass *p2)
{
    CharClass *res = new(Char);

    if (p2->value == 0)
        raise("Division by Zero");
    res->value = p1->value / p2->value;
    return (res);
}

static bool Char_eq(CharClass *p1, CharClass *p2)
{
    if (p1->value == p2->value)
        return (true);
    else
        return (false);
}

static bool Char_lt(CharClass *p1, CharClass *p2)
{
    if (p1->value < p2->value)
        return (true);
    else
        return (false);
}

static bool Char_gt(CharClass *p1, CharClass *p2)
{
    if (p1->value > p2->value)
        return (true);
    else
        return (false);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .value = 0,
};

const Class *Char = (Class *)&_description;
