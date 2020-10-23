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

Test(find_s, find_valid_str)
{
    string_t str;
    string_t str2;
    int test = 0;

    string_init(&str, "Hello World");
    string_init(&str2, "World");
    test = find_s(&str, &str2, 3);
    cr_assert(test == 6);
    string_destroy(&str);
    string_destroy(&str2);
}

Test(find_s, find_invalid_str_to_find)
{
    string_t str;
    string_t str2;
    int test = 0;

    string_init(&str, "Hello World");
    string_init(&str2, "Pouet");
    test = find_s(&str, &str2, 4);
    cr_assert(test == -1);
    string_destroy(&str);
    string_destroy(&str2);
}

Test(find_s, find_invalid_struct)
{
    int test = 0;

    test = find_s(NULL, NULL, 3);
    cr_assert(test == -1);
}

Test(find_s, find_empty_str)
{
    int test = 0;
    string_t str;
    string_t str2;

    string_init(&str, "Hello World");
    string_init(&str2, "");
    test = find_s(&str, &str2, 3);
    cr_assert(test == -1);
    string_destroy(&str);
    string_destroy(&str2);
}