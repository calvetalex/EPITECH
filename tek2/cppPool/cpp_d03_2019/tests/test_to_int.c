/*
** EPITECH PROJECT, 2018
** string
** File description:
** testing to int
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "criterion.h"

Test(to_int, atoi_valid_str)
{
    string_t str;

    string_init(&str, "42");
    cr_assert_eq(to_int(&str), 42);
    string_destroy(&str);
}

Test(to_int, atoi_invalid_str)
{
    string_t str;

    string_init(&str, NULL);
    cr_assert_eq(to_int(&str), -1);
    string_destroy(&str);
}