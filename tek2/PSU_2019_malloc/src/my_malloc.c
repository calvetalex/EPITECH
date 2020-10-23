/*
** EPITECH PROJECT, 2020
** my_malloc
** File description:
** my_malloc
*/

#include <stdint.h>
#include <assert.h>
#include "my_malloc.h"

static void *base = NULL;

stack_t *find_free_space(stack_t **last_elem, size_t new_elem_size)
{
    stack_t *node = base;
    for (; node &&
        !(node->free && new_elem_size <= node->size); node = node->next)
        *last_elem = node;
    return node;
}

stack_t *get_space(stack_t* last, size_t size)
{
    stack_t *new_block = sbrk(0);
    void *request = sbrk(size + _SIZE);

    assert((void*)new_block == request);
    if (request == (void*) -1)
        return NULL;
    if (last)
        last->next = new_block;
    new_block->size = size;
    new_block->next = NULL;
    new_block->free = false;
    return new_block;
}

void *malloc(size_t size)
{
    stack_t *block;

    size = JUSTIFY(size);
    if (size <= 0 || size + _SIZE > SIZE_MAX)
        return NULL;
    if (!base) {
        if (!(block = get_space(NULL, size)))
            return NULL;
        base = block;
    } else {
        stack_t *last = base;
        block = find_free_space(&last, size);
        if (!block) {
            if (!(block = get_space(last, size)))
                return NULL;
        } else
            block->free = false;
    }
    return (block+1);
}