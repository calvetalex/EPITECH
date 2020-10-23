/*
** EPITECH PROJECT, 2018
** test_settings.c
** File description:
** testing init settings
*/

#include <criterion/criterion.h>
#include "my.h"

Test(settings, init_usual)
{
    char *av[6] = {
        "./palindrome",
        "-n",
        "353",
        "-imin",
        "9",
        NULL
    };
    param_t settings = {.base = 10, .nb = 0, .min = 0, .max = 100, \
    .ite = 0, .status = 0};
    int res = 0;

    init_param(&settings, av);
    res = verif_param(&settings);
    cr_assert(settings.nb == 353);
    cr_assert(settings.min == 9);
    cr_assert(settings.max == 100);
    cr_assert(settings.base == 10);
    cr_assert(res == 0);
}

Test(settings, bad_input_given)
{
    char *av[8] = {"./palindrome", "-n", "353", "-imin", "9", \
    "-imax", "5", NULL };
    param_t settings = {.base = 10, .nb = 0, .min = 0, .max = 100, \
    .ite = 0, .status = 0};
    int res = 0;

    init_param(&settings, av);
    res = verif_param(&settings);
    cr_assert(settings.nb == 353);
    cr_assert(settings.min == 9);
    cr_assert(settings.max == 5);
    cr_assert(settings.base == 10);
    cr_assert(res == 84);
}

Test(settings, bad_value_given)
{
    char *av[10] = {"./palindrom", "-n", "34", "-b", "lol", "-imin", "-3",
                    "-imax", "test", NULL};
    param_t set = {10, 0, 0, 100, 0, 0};
    int res = 0;

    init_param(&set, av);
    res = verif_param(&set);
    cr_assert(set.base == -1);
    cr_assert(set.min == -1);
    cr_assert(set.max == -1);
    cr_assert(res == 84);
}

Test(settings, all_value_changed)
{
    char *av[10] = {"./exe", "-n", "34", "-b", "2", "-imin", "6",
                    "-imax", "50", NULL};
    param_t set = {10, 0, 0, 100, 0, 0};
    int res = 0;

    init_param(&set, av);
    res = verif_param(&set);
    cr_assert(set.base == 2);
    cr_assert(set.min == 6);
    cr_assert(set.max == 50);
    cr_assert(res == 0);
}

Test(settings, no_changement)
{
    char *av[4] = {"./exe", "-n", "4", NULL};
    param_t set = {10, 0, 0, 100, 0, 0};

    init_param(&set, av);
    cr_assert(set.base == 10);
    cr_assert(set.min == 0);
    cr_assert(set.max == 100);
}

Test(settings, p_option)
{
    char *av[6] = {"./exe", "-p", "11", "-imax", "2", NULL};
    int res = palindrom(av);

    cr_assert(res == 0);
}

Test(luncher, bad_input_nb)
{
    char *av[6] = {"./exe", "-n","3","-b","0", NULL};
    int res = palindrom(av);

    cr_assert(res == 84);
}

Test(luncher, starting_n_iterat)
{
    char *av[4] = {"./exe", "-n", "10", NULL};
    int res = palindrom(av);

    cr_assert(res == 0);
}
