/*
** EPITECH PROJECT, 2020
** double list
** File description:
** functions to use double
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"

unsigned int double_list_get_size(double_list_t  list)
{
    unsigned int size = 0;
    for (size = 0; list; size++)
        list = list->next;
    return (size);
}

bool double_list_is_empty(double_list_t list)
{
    return (!list);
}

void double_list_dump(double_list_t list)
{
    while (list) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t new = malloc(sizeof(*new));
    if (!new)
        return (false);
    new->value = elem;
    new->next = *front_ptr;
    front_ptr = &new;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double  elem)
{
    double_list_t new = malloc(sizeof(*new));
    if (!new)
        return (false);
    new->value = elem;
    new->next = NULL;
    while (*front_ptr) {
        *front_ptr = (*front_ptr)->next;
    }
    (*front_ptr)->next = &new;
    return (true);
}