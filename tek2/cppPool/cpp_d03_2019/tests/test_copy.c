/*
** EPITECH PROJECT, 2018
** string
** File description:
** testing compare
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "criterion.h"

Test(copy, copy_valid_str)
{
    string_t str;
    char *str2 = strdup("World");
    int test = 0;

    string_init(&str, "Hello");
    test = copy(&str, str2, 2, 1);
    cr_assert(test == 2, "Got %d\n", test);
    string_destroy(&str);
    free(str2);
}

Test(copy, copy_part_of_str)
{
    string_t str;
    char *str2 = strdup("World");
    int test = 0;

    string_init(&str, "Hello");
    test = copy(&str, str2, 1, 2);
    cr_assert(test == 1, "Got %d\n", test);
    string_destroy(&str);
    free(str2);
}

Test(copy, copy_invalid_str)
{
    string_t str;
    char *str2 = strdup("World");
    int test = 0;

    string_init(&str, NULL);
    test = copy(&str, str2, 3, 1);
    cr_assert(test == 0, "Got %d\n", test);
    string_destroy(&str);
    free(str2);
}

Test(copy, copy_invalid_struct)
{
    string_t str;
    char *str2 = NULL;
    int test = 0;

    string_init(&str, "Hello");
    test = copy(&str, str2, 0, 4);
    cr_assert(test == 0, "Got %d\n", test);
    string_destroy(&str);
}

Test(copy, copy_more_of_str)
{
    string_t str;
    char *str2 = strdup("World");
    int test = 0;

    string_init(&str, "Hello");
    test = copy(&str, str2, 3, 3);
    cr_assert(test == 3, "Got %d\n", test);
    string_destroy(&str);
    free(str2);
}