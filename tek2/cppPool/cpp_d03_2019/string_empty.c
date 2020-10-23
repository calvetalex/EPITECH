/*
** EPITECH PROJECT, 2020
** string
** File description:
** check empty string
*/

#include <stdbool.h>
#include <string.h>
#include "string.h"

int empty(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (strlen(this->str) == 0 ? true : false);
}