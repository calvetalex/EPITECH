/*
** EPITECH PROJECT, 2018
** test_requirement.c
** File description:
** TU for equirement
*/

#include <criterion/criterion.h>

int my_factrec_synthesis(int nb);

int my_squareroot_synthesis(int nb);

Test(requirement, factrec_ez)
{
    int nb = 5;

    nb = my_factrec_synthesis(nb);
    cr_assert(nb == 120, "Expected 120 but got %d\n", nb);
}

Test(requirement, fractal_egual_one)
{
    int nb = 0;
    int test = 1;

    nb = my_factrec_synthesis(nb);
    test = my_factrec_synthesis(test);
    cr_assert(nb == 1);
    cr_assert(test == 1);
}

Test(requirement, factrec_bad_nb)
{
    int nb = -4;
    int test = 14;

    test = my_factrec_synthesis(test);
    nb = my_factrec_synthesis(nb);
    cr_assert(nb == 0);
    cr_assert(test == 0);
}

Test(requirement, sqrt_classic)
{
    int nb = 144;

    nb = my_squareroot_synthesis(nb);
    cr_assert(nb == 12, "Expected 12 but got %d\n", nb);
}

Test(requirement, sqrt_not_whole_nb)
{
    int nb = 2;

    nb = my_squareroot_synthesis(nb);
    cr_assert(nb == -1);
}

Test(requirement, sqrt_bad_input)
{
    int nb = -6;

    nb = my_squareroot_synthesis(nb);
    cr_assert(nb == -1);
}

Test(requirement, sqrt_nb_one)
{
    int nb = 1;

    nb = my_squareroot_synthesis(nb);
    cr_assert(nb == 1);
}

Test(requirement, sqrt_nb_null)
{
    int nb = 0;

    nb = my_squareroot_synthesis(nb);
    cr_assert(nb == 0);
}
