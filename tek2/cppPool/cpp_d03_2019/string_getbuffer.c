/*
** EPITECH PROJECT, 2020
** string
** File description:
** get buffer of current instance
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (!this)
        return (NULL);
    return (this->str);
}