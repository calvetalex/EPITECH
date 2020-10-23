/*
** EPITECH PROJECT, 2018
** string
** File description:
** testing find
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "criterion.h"

Test(size, iget_size_valid_str)
{
    string_t str;
    int len = 0;

    string_init(&str, "Pouet");
    len = size(&str);
    cr_assert_eq(len, 5);
    string_destroy(&str);
}

Test(size, get_size_valid_str)
{
    string_t str;
    int len = 0;

    string_init(&str, NULL);
    len = size(&str);
    cr_assert_eq(len, -1);
    string_destroy(&str);
}