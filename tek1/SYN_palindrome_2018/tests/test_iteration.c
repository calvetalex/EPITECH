/*
** EPITECH PROJECT, 2018
** test_iteration.c
** File description:
** testing iteration function
*/

#include <criterion/criterion.h>
#include "my.h"

Test(make_iteration_testing, small_int_base_10)
{
    param_t set = {10, 123, 0, 100, 0, 0};
    int nb = 123;

    nb = make_iteration(&set, nb);
    cr_assert(nb == 444, "Expected 444 but got %d\n");
}

Test(make_iteration_testing, big_int_base_10)
{
    param_t set = {10, 123, 0, 100, 0, 0};
    int nb = 1000000;

    nb = make_iteration(&set, nb);
    cr_assert(nb == 1000001, "Expected 1000001 but got %d\n");
}

Test(make_iteration, other_base_test)
{
    param_t set = {2, 123, 0, 100, 0, 0};
    int nb = 64;

    nb = make_iteration(&set, nb);
    cr_assert(nb == 65, "Expected 65 but got %d\n");
}