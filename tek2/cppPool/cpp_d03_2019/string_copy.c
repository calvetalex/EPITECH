/*
** EPITECH PROJECT, 2020
** string
** File description:
** copy strings
*/

#include <string.h>
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t  pos)
{
    size_t i = pos;

    if (!this || !this->str || !s || pos > (size_t)strlen(this->str) || n < 1)
        return (0);
    for (i = pos; this->str[i] != '\0' && i < pos + n; i++)
        s[i - pos] = this->str[i];
    if (i < pos + n && this->str[i] == '\0') {
        s[i - pos] = '\0';
        i++;
    }
    return (i - pos);
}