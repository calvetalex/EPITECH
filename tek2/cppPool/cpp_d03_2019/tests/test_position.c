/*
** EPITECH PROJECT, 2018
** string
** File description:
** testing assign
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "criterion.h"

Test(at, at_valid_pos)
{
    string_t str;
    char c = '\0';

    string_init(&str, "Hello World");
    c = at(&str, 4);
    cr_assert(c == 'o');
    string_destroy(&str);
}

Test(at, at_invalid_pos)
{
    string_t str;
    char c = '\0';

    string_init(&str, "Hello World");
    c = at(&str, 42);
    cr_assert(c == -1);
    string_destroy(&str);
}

Test(at, at_invalid_str)
{
    string_t str;
    char c = '\0';

    string_init(&str, NULL);
    c = at(&str, 42);
    cr_assert(c == -1);
    string_destroy(&str);
}

Test(at, at_invalid_struct)
{
    string_t str = {0};
    char c = '\0';

    c = at(&str, 0);
    cr_assert(c == -1);
    string_destroy(&str);
}