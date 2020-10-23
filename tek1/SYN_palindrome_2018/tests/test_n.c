/*
** EPITECH PROJECT, 2018
** test_n.c
** File description:
** testing -n flag
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect(void)
{
    cr_redirect_stdout();
}

Test(n_iteration, good_argument_value, .init=redirect)
{
    param_t set = {2, 64, 0, 100, 0, 0};
    int res = start_iteration_n(&set, 64);
    char *check = "64 leads to 65 in 1 iteration(s) in base 2\n";

    cr_assert_stdout_eq_str(check);
    cr_assert(res == 0, "Expected 0 got %d\n", res);
}

Test(n_iteration, no_solution, .init=redirect)
{
    param_t set = {10, 1, 6, 7, 0, 0};
    int res = start_iteration_n(&set, 1);
    char *check = "no solution\n";

    cr_assert_stdout_eq_str(check);
    cr_assert(res == 0, "Expected 0 but got %d\n", res);
}

Test(n_iteration, no_iteration, .init=redirect)
{
    param_t set = {10, 36, 4, 12 , 13, 0};
    int nb = 36;
    int res = start_iteration_n(&set, nb);

    cr_assert_stdout_eq_str("no solution\n");
    cr_assert(res == 0);
}
