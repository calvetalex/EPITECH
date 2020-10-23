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


Test(c_str, get_valid_str)
{
    string_t str;

    string_init(&str, "Hello");
    cr_assert_str_eq(c_str(&str), "Hello");
    string_destroy(&str);
}

Test(c_str, get_invalid_struct)
{
    cr_assert_eq(c_str(NULL), NULL);
}

Test(c_str, get_invalid_str)
{
    string_t str;

    string_init(&str, NULL);
    cr_assert_eq(c_str(&str), NULL);
    string_destroy(&str);
}