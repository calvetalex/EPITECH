/*
** EPITECH PROJECT, 2020
** string
** File description:
** search in string
*/

#include <string.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (!this || !this->str || !str || !str->str || pos > strlen(this->str) ||
    strlen(this->str) == 0 || strlen(str->str) == 0)
        return (-1);
    if (strstr(&this->str[pos], str->str))
        return ((strstr(&this->str[pos], str->str)) - this->str);
    return (-1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    if (!this || !this->str || !str || pos > strlen(this->str) ||
    strlen(this->str) == 0 || strlen(str) == 0)
        return (-1);
    if (strstr(&this->str[pos], str))
        return ((strstr(&this->str[pos], str)) - this->str);
    return (-1);
}
