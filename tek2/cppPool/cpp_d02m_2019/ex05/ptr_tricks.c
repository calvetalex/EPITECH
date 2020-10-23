/*
** EPITECH PROJECT, 2020
** ptr tricks
** File description:
** pointer master
*/

#include <stdlib.h>
#include <stddef.h>
#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    return (abs(ptr2 - ptr1));
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    return (whatever_t *)((size_t) member_ptr - offsetof(whatever_t, member));
}