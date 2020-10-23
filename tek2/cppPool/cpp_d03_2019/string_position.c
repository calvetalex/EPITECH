/*
** EPITECH PROJECT, 2020
** string
** File description:
** get char at position X from string
*/

#include <stddef.h>
#include <string.h>
#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (!this || !this->str || pos > strlen(this->str))
        return (-1);
    return (this->str[pos]);
}