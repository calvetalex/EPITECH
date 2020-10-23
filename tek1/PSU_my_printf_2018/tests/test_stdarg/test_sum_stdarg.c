/*
** EPITECH PROJECT, 2018
** test_sum_stdarg.c
** File description:
** tests for sum_stdarg()
*/
#include <criterion/criterion.h>
#include "../include/my.h"

Test(sum_stdarg, sum_stdarg_int)
{
    int res = 0;

    res = sum_stdarg(0, 3, 1, 2, 3);
    cr_assert_eq(res, 6);
}

Test(sum_stdarg, sum_stdarg_char)
{
    int res = 0;

    res = sum_stdarg(1, 5, "Hello", "a", "toto", "", "plop");
    cr_assert_eq(res, 14);
}

Test(sum_stdarg, sum_stdarg_invalid_input)
{
    int res = 0;

    res = sum_stdarg(2, 3, 1, 3, 4);
    cr_assert_eq(res, 84);
}
