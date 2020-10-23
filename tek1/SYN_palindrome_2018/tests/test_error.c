/*
** EPITECH PROJECT, 2018
** test_error.c
** File description:
** TU for error handling
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(main_error_handling, good_argument_value)
{
    char *av[10] = {
        "./palindrome",
        "-n",
        "363",
        "-b",
        "2",
        "-imin",
        "4",
        "-imax",
        "250",
        NULL
    };
    int res = argv_handle(9, av);

    cr_assert(res == 0, "Expected 0 but got %d\n", res);
}

Test(main_error_handling, bad_arguments_nb)
{
    char *av[5] = {
        "./palindrome",
        "-n",
        "456",
        "toto",
        NULL
    };
    int res = argv_handle(4, av);

    cr_assert(res == 84, "Expected 84 but got %d\n", res);
}

Test(main_error_handling, bad_value_argument)
{
    char *av[4] = {
        "./palindrome",
        "-p",
        "-363",
        NULL
    };
    int res = argv_handle(3, av);

    cr_assert(res == 84, "Expected 84 but got %d\n", res);
}

Test(main_error_handling, help_asking)
{
    char *av[3] = {"./palindrome", "-h", NULL};

    cr_assert(argv_handle(2, av) == 0);
}

Test(main_error_handling, bad_start_option)
{
    char *av[4] = {"./palindrome", "-b", "2", NULL};
    int res = argv_handle(3, av);

    cr_assert(res == 84);
}

Test(main_error_handling, n_and_p_option)
{
    char *av[6] = {"./palindrom", "-n", "4", "-p", "363", NULL};
    int res = argv_handle(5, av);

    cr_assert(res == 84);
}

Test(main_error_handling, no_nb_given)
{
    char *av[8] = {"./exe", "-n", "5", "-imin", "lol", "-b", "tot", NULL};
    int res = argv_handle(7, av);

    cr_assert(res == 84);
}

Test(main_error_handling, no_option)
{
    char *av[2] = {"./palindrom", NULL};
    int res = argv_handle(1, av);

    cr_assert(res == 84);
}
