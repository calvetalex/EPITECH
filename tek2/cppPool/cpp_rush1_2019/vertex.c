/*
** EPITECH PROJECT, 2020
** rush 1
** File description:
** Vertex Class
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include "new.h"
#include "vertex.h"
#include "raise.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        raise("Object must be allocated!");
    this->x = args[0] ? (int) va_arg(*args, int) : 0;
    this->y = args[1] ? (int) va_arg(*args, int) : 0;
    this->z = args[2] ? (int) va_arg(*args, int) : 0;
    return;
}

static void Vertex_dtor(VertexClass *this)
{
    if (!this)
        raise("Object musst be allocated!");
    return;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = NULL;

    if (!this)
        raise("Value must be initialize!");
    asprintf(&str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

VertexClass *Vertex_add(VertexClass *a, VertexClass *b)
{
    VertexClass *res = new(Vertex);

    res->x = a->x + b->x;
    res->y = a->y + b->y;
    res->z = a->z + b->z;
    return (res);
}

VertexClass *Vertex_sub(VertexClass *a, VertexClass *b)
{
    VertexClass *res = new(Vertex);

    res->x = a->x - b->x;
    res->y = a->y - b->y;
    res->z = a->z - b->z;
    return (res);
}

// Create additional functions here

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Vertex = (const Class *)&_description;