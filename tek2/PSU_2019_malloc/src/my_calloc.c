/*
** EPITECH PROJECT, 2020
** my_calloc
** File description:
** my_calloc
*/

#include <string.h>
#include "malloc.h"

void *calloc(size_t nbmbr, size_t size)
{
    void *ptr = NULL;
    size_t new_size = nbmbr * size;

    ptr = malloc(new_size);
    if (ptr)
        memset(ptr, 0, new_size);
    return ptr;
}