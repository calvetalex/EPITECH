/*
** EPITECH PROJECT, 2020
** string
** File description:
** get string size
*/

#include <string.h>
#include "string.h"

int size(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (strlen(this->str));
}