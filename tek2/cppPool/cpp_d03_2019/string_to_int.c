/*
** EPITECH PROJECT, 2020
** string
** File description:
** transform str in int
*/

#include <stdlib.h>
#include "string.h"

int to_int(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (atoi(this->str));
}