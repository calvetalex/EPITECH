/*
** EPITECH PROJECT, 2018
** string
** File description:
** testing insert
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "criterion.h"

Test(insert_c, insert_valid_str)
{
    string_t str;

    string_init(&str, "Hello World");
    insert_c(&str, 5, "PoueT");
    cr_assert_str_eq(str.str, "HelloPoueT World");
    string_destroy(&str);
}

Test(insert_c, insert_invalid_str)
{
    string_t str;

    string_init(&str, "Hello World");
    insert_c(&str, 4, NULL);
    cr_assert_str_eq(str.str, "Hello World");
    string_destroy(&str);
}

Test(insert_c, insert_valid_str_at_end)
{
    string_t str;

    string_init(&str, "Hello");
    insert_c(&str, 6, "POUET");
    cr_assert_str_eq(str.str, "HelloPOUET");
    string_destroy(&str);
}

Test(insert_c, insert_valid_struct)
{
    string_t str;

    string_init(&str, NULL);
    insert_c(&str, 4, "Hello World");
    cr_assert_str_eq(str.str, "Hello World");
    string_destroy(&str);
}