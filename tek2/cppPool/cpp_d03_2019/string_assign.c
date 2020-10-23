/*
** EPITECH PROJECT, 2020
** string
** File description:
** asign element to another string module
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this->str)
        free(this->str);
    this->str = strdup(str->str);
    return;
}

void assign_c(string_t *this, const char *s)
{
    if (this->str)
        free(this->str);
    this->str = strdup(s);
    return;
}