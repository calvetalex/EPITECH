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

Test(clear, clear_valid_str)
{
    string_t str;

    string_init(&str, "boBON");
    clear(&str);
    cr_assert_str_eq(str.str, "");
    string_destroy(&str);
}