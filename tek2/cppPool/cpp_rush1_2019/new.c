/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** new
*/

#include <stdio.h>
#include <string.h>
#include "new.h"

Object *new(const Class *class, ...)
{
    va_list params = {0};

    if (!class)
        raise("Invalid arguments");
    va_start(params, class);
    return (va_new(class, &params));
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *obj = NULL;

    if (!class || !ap)
        raise("Invalid arguments");
    obj = malloc(class->__size__);
    memcpy(obj, class, class->__size__);
    if (obj->__ctor__ != NULL)
        obj->__ctor__(obj, ap);
    va_end(*ap);
    return (obj);
}

void delete(Object *ptr)
{
    Class *obj = ptr;

    if (!ptr)
        raise("Object must be allocated");
    if (obj->__dtor__)
        obj->__dtor__(ptr);
    free(ptr);
}