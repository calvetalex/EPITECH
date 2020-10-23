/*
** EPITECH PROJECT, 2018
** test_print.c
** File description:
** testing putX functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirection(void)
{
    cr_redirect_stdout();
}

Test(putstr_difficult, two_putstr_to_print_str, .init=redirection)
{
    char *str = "BATMAN";
    char *check = "BATMAN was the correct answer\n";

    my_putstr(my_putstr(str) + " was the correct answer\n");
    cr_assert_stdout_eq_str(check);
}

Test(putstr_difficult, putstr_putnbr_to_print_nbr, .init=redirection)
{
    int nb = 42;
    char *check = "42 was the correct answer\n";

    my_putstr(putnbr(nb) + " was the correct answer\n");
    cr_assert_stdout_eq_str(check);
}