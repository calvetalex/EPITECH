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

Test(insert_s, insert_valid_str)
{
    string_t str;
    string_t str2;

    string_init(&str, "Hello World");
    string_init(&str2, "PoueT");
    insert_s(&str, 5, &str2);
    cr_assert_str_eq(str.str, "HelloPoueT World");
    string_destroy(&str);
    string_destroy(&str2);
}

Test(insert_s, insert_invalid_str)
{
    string_t str;
    string_t str2;

    string_init(&str, "Hello World");
    string_init(&str2, NULL);
    insert_s(&str, 4, &str2);
    cr_assert_str_eq(str.str, "Hello World");
    string_destroy(&str);
    string_destroy(&str2);
}

Test(insert_s, insert_valid_str_at_end)
{
    string_t str;
    string_t str2;

    string_init(&str, "Hello");
    string_init(&str2, "POUET");
    insert_s(&str, 6, &str2);
    cr_assert_str_eq(str.str, "HelloPOUET");
    string_destroy(&str);
    string_destroy(&str2);
}

Test(insert_s, insert_str_on_null_str)
{
    string_t str;
    string_t str2;

    string_init(&str, NULL);
    string_init(&str2, "POUET");
    insert_s(&str, 5, &str2);
    cr_assert_str_eq(str.str, "POUET");
    string_destroy(&str);
    string_destroy(&str2);
}

Test(insert_s, insert_valid_struct)
{
    string_t str;

    string_init(&str, "Hello World");
    insert_s(&str, 4, NULL);
    cr_assert_str_eq(str.str, "Hello World");
    string_destroy(&str);
}