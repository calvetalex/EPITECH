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

Test(assign_c, assign_str_to_string_from_char)
{
    string_t str;

    string_init(&str, "init");
    assign_c(&str, "bonjour !");
    cr_assert_str_eq(str.str, "bonjour !");
    string_destroy(&str);
}

Test(assign_c, assign_str_to_string_from_char_with_no_str_init)
{
    string_t str;

    string_init(&str, NULL);
    assign_c(&str, "bonjour !");
    cr_assert_str_eq(str.str, "bonjour !");
    string_destroy(&str);
}

Test(assign_s, assign_str_to_string_from_char)
{
    string_t str;
    string_t test;

    string_init(&test, "hola !");
    string_init(&str, "que tal ?");
    assign_s(&str, &test);
    cr_assert_str_eq(str.str, test.str);
    string_destroy(&str);
    string_destroy(&test);
}

Test(assign_s, assign_str_to_string_from_char_with_no_str_init)
{
    string_t str;
    string_t test;

    string_init(&test, "hola !");
    string_init(&str, NULL);
    assign_s(&str, &test);
    cr_assert_str_eq(str.str, test.str);
    string_destroy(&str);
    string_destroy(&test);
}