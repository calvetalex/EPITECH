/*
** EPITECH PROJECT, 2020
** double list
** File description:
** functions to use double lsit
*/

#include <stddef.h>
#include <stdlib.h>
#include "double_list.h"

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
    unsigned int position)
{
    unsigned int tmp = 0;
    double_list_t list = *front_ptr;
    double_list_t new = malloc(sizeof(*new));
    if (!new)
        return (false);
    new->value = elem;
    new->next = NULL;
    if (position == 0) {
        new->next = *front_ptr;
        front_ptr = &new;
        return (true);
    }
    while (tmp < position) {
        list = list->next;
        tmp++;
    }
    new->next = list->next;
    list->next = new;
    return (true);
}

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t tmp;

    if (!*front_ptr)
        return (false);
    tmp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t list = *front_ptr;

    if (!*front_ptr)
        return (false);
    while (list)
        list = list->next;
    free(list);
    return (true);
}

bool double_list_del_elem_at_position(double_list_t *front_ptr,
    unsigned int position)
{
    double_list_t list = *front_ptr;
    double_list_t tmp;
    unsigned int i = 0;
    if (!*front_ptr)
        return (false);
    if (position == 0) {
        tmp = list;
        *front_ptr = list->next;
        free(tmp);
        return (true);
    }
    for (i = 0; list && i < position; i++)
        list = list->next;
    if (i < position)
        return (false);
    tmp = list;
    list = list->next;
    free(tmp);
    return (true);
}

double  double_list_get_elem_at_front(double_list_t  list)
{
    if (!list)
        return (0);
    return (list->value);
}