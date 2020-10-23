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

Test(find_c, find_valid_str)
{
    string_t str;
    int test = 0;

    string_init(&str, "Hello World");
    test = find_c(&str, "World", 3);
    cr_assert(test == 6);
    string_destroy(&str);
}

Test(find_c, find_invalid_str_to_find)
{
    string_t str;
    int test = 0;

    string_init(&str, "Hello World");
    test = find_c(&str, "Pouet", 3);
    cr_assert(test == -1);
    string_destroy(&str);
}

Test(find_c, find_invalid_struct)
{
    int test = 0;

    test = find_c(NULL, NULL, 3);
    cr_assert(test == -1);
}

Test(find_c, find_empty_str)
{
    int test = 0;
    string_t str;

    string_init(&str, "Hello World");
    test = find_c(&str, "", 3);
    cr_assert(test == -1);
    string_destroy(&str);
}