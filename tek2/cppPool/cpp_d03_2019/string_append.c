/*
** EPITECH PROJECT, 2020
** string
** File description:
** concat strings
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (!this->str) {
        this->str = strdup(ap->str);
        return;
    }
    this->str = realloc(this->str, (sizeof(*(this->str)) *
        (strlen(this->str) + strlen(ap->str) + 1)));
    strcat(this->str, ap->str);
    return;
}

void append_c(string_t *this, const char *ap)
{
    if (!this->str) {
        this->str = strdup(ap);
        return;
    }
    this->str = realloc(this->str, (sizeof(*(this->str)) *
        (strlen(this->str) + strlen(ap) + 1)));
    strcat(this->str, ap);
    return;
}