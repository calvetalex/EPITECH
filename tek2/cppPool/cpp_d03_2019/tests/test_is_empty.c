/*
** EPITECH PROJECT, 2018
** string
** File description:
** testing c_str
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "criterion.h"

Test(empty, invalid_str)
{
    string_t str;

    string_init(&str, NULL);
    cr_assert_eq(empty(&str), -1);
    string_destroy(&str);
}

Test(empty, invalid_struct)
{
    cr_assert_eq(empty(NULL), -1);
}

Test(empty, not_empty_str)
{
    string_t str;

    string_init(&str, "Hello");
    cr_assert_eq(empty(&str), false);
    string_destroy(&str);
}

Test(empty, empty_str)
{
    string_t str;

    string_init(&str, "");
    cr_assert_eq(empty(&str), true);
    string_destroy(&str);
}