/*
** EPITECH PROJECT, 2020
** string
** File description:
** insert string in another
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    int length = 0;
    char *new_string = NULL;

    if (!this || !str || !str->str)
        return;
    if (!this->str) {
        this->str = strdup(str->str);
        return;
    }
    if (pos > strlen(this->str))
        return append_s(this, str);
    new_string = calloc(strlen(this->str) + strlen(str->str) + 1, sizeof(char));
    memcpy(new_string, this->str, pos);
    memcpy(new_string + pos, str->str, pos + strlen(str->str));
    memcpy(new_string + pos + strlen(str->str), this->str + pos,
        strlen(this->str) - pos);
    free(this->str);
    this->str = new_string;
    return;
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    int length = 0;
    char *new_string = NULL;

    if (!this || !str)
        return;
    if (!this->str) {
        this->str = strdup(str);
        return;
    }
    if (pos > strlen(this->str))
        return append_c(this, str);
    new_string = calloc(strlen(this->str) + strlen(str) + 1, sizeof(char));
    memcpy(new_string, this->str, pos);
    memcpy(new_string + pos, str, pos + strlen(str));
    memcpy(new_string + pos + strlen(str), this->str + pos,
        strlen(this->str) - pos);
    free(this->str);
    this->str = new_string;
    return;
}