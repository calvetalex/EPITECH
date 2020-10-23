/*
** EPITECH PROJECT, 2018
** string
** File description:
** testing append
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "criterion.h"

Test(append_c, append_str_to_string_from_char)
{
    string_t str;

    string_init(&str, "init");
    append_c(&str, " Append_c marche!");
    cr_assert_str_eq(str.str, "init Append_c marche!");
    string_destroy(&str);
}

Test(append_c, append_str_to_string_from_char_w_no_str_init)
{
    string_t str;

    string_init(&str, NULL);
    append_c(&str, "Append_c marche!");
    cr_assert_str_eq(str.str, "Append_c marche!");
    string_destroy(&str);
}

Test(append_s, append_str_to_string_from_char)
{
    string_t str;
    string_t test;

    string_init(&str, "init");
    string_init(&test, "BONJOUR");
    append_s(&str, &test);
    cr_assert_str_eq(str.str, "initBONJOUR");
    string_destroy(&str);
    string_destroy(&test);
}

Test(append_s, append_str_to_string_from_char_w_no_str_init)
{
    string_t str;
    string_t test;

    string_init(&str, NULL);
    string_init(&test, "BONJOUR");
    append_s(&str, &test);
    cr_assert_str_eq(str.str, "BONJOUR");
    string_destroy(&str);
    string_destroy(&test);
}