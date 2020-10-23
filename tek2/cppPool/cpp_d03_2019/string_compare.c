/*
** EPITECH PROJECT, 2020
** string
** File description:
** compare strings
*/

#include <string.h>
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (!this->str && !str->str)
        return (0);
    else if (!this->str || !str->str)
        return (-1);
    else
        return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (!this->str && !str)
        return (0);
    else if (!this->str || !str)
        return (-1);
    else
        return (strcmp(this->str, str));
}