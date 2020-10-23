/*
** EPITECH PROJECT, 2020
** realloc
** File description:
** allocate more memory if needed
*/


#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    stack_t* block = NULL;
    void *new_ptr = NULL;

    if (!ptr)
        return malloc(size);
    block = get_block(ptr);
    if (block->size >= size)
        return ptr;
    new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;
    memcpy(new_ptr, ptr, block->size);
    free(ptr);
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nb, size_t size)
{
    ptr = realloc(ptr, (size * nb));
    return ptr != NULL ? ptr : malloc(sizeof(ptr) * 1);
}