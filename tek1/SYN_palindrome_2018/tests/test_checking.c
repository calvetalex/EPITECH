/*
** EPITECH PROJECT, 2018
** test_checking.c
** File description:
** testing checking palindromic nb
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirected(void)
{
    cr_redirect_stdout();
}

Test(checkin_palindrom_nb, check_palindrom_base_10, .init=redirected)
{
    param_t set = {10, 101, 0, 100, 0, 0};
    int nb = 101;
    int res = check_palindrome_n(&set, nb);

    cr_assert(res == 0, "Expected 0 but got %d\n");
}

Test(checkin_palindrom_nb, check_palindrom_base_2, .init=redirected)
{
    param_t set = {2, 64, 0, 100, 1, 0};
    int nb = 65;
    int res = check_palindrome_n(&set, nb);
    char *str = "64 leads to 65 in 1 iteration(s) in base 2\n";

    cr_assert_stdout_eq_str(str);
    cr_assert(res == 0, "Expected 0 but got %d\n");
}

Test(checkin_palindrom_nb, check_no_palindrom, .init=redirected)
{
    param_t set = {10, 123, 0, 100, 0, 0};
    int nb = 123;
    int res = check_palindrome_n(&set, nb);

    cr_assert(res == 84, "Expected 84 but got %d\n");
}

Test(checkin_palindrom_nb, check_palindrom_print_base_10, .init=redirected)
{
    param_t set = {10, 123, 0, 100, 1, 0};
    int nb = 444;
    int res = check_palindrome_n(&set, nb);
    char *str = "123 leads to 444 in 1 iteration(s) in base 10\n";

    cr_assert_stdout_eq_str(str);
    cr_assert(res == 0, "Expected 0 but got %d\n");
}