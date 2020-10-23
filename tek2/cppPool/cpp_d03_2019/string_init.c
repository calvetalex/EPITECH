/*
** EPITECH PROJECT, 2020
** string
** File description:
** init and destroy string
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

static void init_string_functions(string_t *this)
{
    this->string_init = &string_init;
    this->string_destroy = &string_destroy;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
}

void string_init(string_t *this, const char *s)
{
    if (!this)
        return;
    if (!s)
        this->str = NULL;
    else
        this->str = strdup(s);
    init_string_functions(this);
    return;
}

void string_destroy(string_t *this)
{
    if (!this || !this->str)
        return;
    free(this->str);
    return;
}