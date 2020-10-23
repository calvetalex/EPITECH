/*
** EPITECH PROJECT, 2018
** test_p.c
** File description:
** TU for -p option
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirectioning(void)
{
    cr_redirect_stdout();
}

Test(p_iteration, good_argument, .init=redirectioning)
{
    param_t set = {10, 363, 6, 100, 0, 0};
    int res = start_iteration_p(&set);
    char *check = "3 leads to 363 in 6 iteration(s) in base 10\n";

    cr_assert_stdout_eq_str(check);
    cr_assert(res == 0);
}

Test(p_iteration, no_solution, .init=redirectioning)
{
    param_t set = {10, 363, 7, 100, 0, 0};
    int res = start_iteration_p(&set);
    char *check = "no solution\n";

    cr_assert_stdout_eq_str(check);
    cr_assert(res == 0, "Expected 0 but got %d\n", res);
}

Test(p_iteration, bad_input_given)
{
    char *av[4] = {
        "./palindrome",
        "-p",
        "139"
    };
    int res = palindrom(av);

    cr_assert(res == 84, "Expected 84 but got %d\n", res);
}