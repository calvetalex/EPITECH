/*
** EPITECH PROJECT, 2020
** string
** File description:
** clear string
*/

#include <string.h>
#include "string.h"

void clear(string_t *this)
{
    memset(this->str, 0, strlen(this->str));
    return;
}