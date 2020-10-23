/*
** EPITECH PROJECT, 2018
** string
** File description:
** testing compare
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "criterion.h"

Test(compare_s, compare_same_str)
{
    string_t str;
    string_t str2;
    int test = 0;

    string_init(&str, "Hello World");
    string_init(&str2, "Hello World");
    test = compare_s(&str, &str2);
    cr_assert(test == 0);
    string_destroy(&str);
    string_destroy(&str2);
}

Test(compare_s, compare_str_up_str2)
{
    string_t str;
    string_t str2;
    int test = 0;

    string_init(&str, "Hello World");
    string_init(&str2, "Jello World");
    test = compare_s(&str, &str2);
    cr_assert(test == -2);
    string_destroy(&str);
    string_destroy(&str2);
}

Test(compare_s, compare_str_down_str2)
{
    string_t str;
    string_t str2;
    int test = 0;

    string_init(&str, "Hello World");
    string_init(&str2, "Ello World");
    test = compare_s(&str, &str2);
    cr_assert(test == 3);
    string_destroy(&str);
    string_destroy(&str2);
}

Test(compare_s, compare_invalid_str)
{
    string_t str;
    string_t str2;
    int test = 0;

    string_init(&str, NULL);
    string_init(&str2, "Hello world");
    test = compare_s(&str, &str2);
    cr_assert(test == -1);
    string_destroy(&str);
    string_destroy(&str2);
}

Test(compare_s, compare_null_str)
{
    string_t str;
    string_t str2;
    int test = 0;

    string_init(&str, NULL);
    string_init(&str2, NULL);
    test = compare_s(&str, &str2);
    cr_assert(test == 0);
    string_destroy(&str);
    string_destroy(&str2);
}