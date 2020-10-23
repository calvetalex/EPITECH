/*
** EPITECH PROJECT, 2020
** double list
** File description:
** functions to use double list
*/

#include <stddef.h>
#include "double_list.h"

double double_list_get_elem_at_back(double_list_t  list)
{
    if (!list)
        return (0);
    while (list->next)
        list = list->next;
    return (list->value);
}

double double_list_get_elem_at_position(double_list_t list,
    unsigned int position)
{
    unsigned int i = 0;
    if (!list)
        return (0);
    if (position == 0)
        return (list->value);
    while (list && i < position) {
        list = list->next;
        i++;
    }
    if (i < position)
        return (0);
    return (list->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
    double value)
{
    while (list && list->value != value)
        list = list->next;
    if (!list)
        return (NULL);
    return (list);
}