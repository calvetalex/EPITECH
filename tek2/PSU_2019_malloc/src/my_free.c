/*
** EPITECH PROJECT, 2020
** free.c
** File description:
** my_free
*/

#include <assert.h>
#include "my_malloc.h"

stack_t *get_block(void *ptr)
{
    return (stack_t *)ptr - 1;
}

void free(void *ptr)
{
    if (!ptr)
        return;
    stack_t * block = get_block(ptr);
    assert(block->free == false);
    block->free = true;
}