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

Test(compare_c, compare_same_str)
{
    string_t str;
    int test = 0;

    string_init(&str, "Hello World");
    test = compare_c(&str, "Hello World");
    cr_assert(test == 0);
    string_destroy(&str);
}

Test(compare_c, compare_str_up_str2)
{
    string_t str;
    int test = 0;

    string_init(&str, "Hello World");
    test = compare_c(&str, "Jello World");
    cr_assert(test == -2);
    string_destroy(&str);
}

Test(compare_c, compare_str_down_str2)
{
    string_t str;
    int test = 0;

    string_init(&str, "Hello World");
    test = compare_c(&str, "Ello World");
    cr_assert(test == 3);
    string_destroy(&str);
}

Test(compare_c, compare_invalid_str)
{
    string_t str;
    int test = 0;

    string_init(&str, NULL);
    test = compare_c(&str, "Hello World");
    cr_assert(test == -1);
    string_destroy(&str);
}

Test(compare_c, compare_null_str)
{
    string_t str;
    int test = 0;

    string_init(&str, NULL);
    test = compare_c(&str, NULL);
    cr_assert(test == 0);
    string_destroy(&str);
}