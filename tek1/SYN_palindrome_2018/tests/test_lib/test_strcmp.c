/*
** EPITECH PROJECT, 2018
** test_strcmp.c
** File description:
** testing strcmp function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "my.h"

Test(test_strcmp, str1_before_str2)
{
    char *str1 = "before";
    char *str2 = "end";
    int res = my_strcmp(str1, str2);

    cr_assert(res == -1, "Expected -1 but got %d\n", res);
}

Test(test_strcmp, str1_after_str2)
{
    char *str1 = "Testing";
    char *str2 = "Making";
    int res = my_strcmp(str1, str2);

    cr_assert(res == 1, "Expected 1 but got %d\n", res);
}

Test(test_strcmp, str1_eq_str2)
{
    char *str1 = "same";
    char *str2 = "same";
    int res = my_strcmp(str1, str2);

    cr_assert(res == 0, "Expected 0 but got %d\n", res);
}

Test(test_strcmp, str1_null)
{
    char *str1 = NULL;
    char *str2 = "end";
    int res = my_strcmp(str1, str2);

    cr_assert(res == 0, "Expected 0 but got %d\n", res);
}