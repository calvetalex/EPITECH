/*
** EPITECH PROJECT, 2018
** test_sti.c
** File description:
** TU ofr str_to_int and int_to_str function
*/

#include <criterion/criterion.h>
#include "my.h"

Test(str_to_int, str_to_int_short)
{
    char *str = "42";
    int res = str_to_int(str);

    cr_assert(res == 42, "Expected 42 but got %d\n", res);
}

Test(str_to_int, str_to_int_long)
{
    char *str = "1234567890";
    int res = str_to_int(str);

    cr_assert(res == 1234567890, "Expected 1234567890 but got %d\n", res);
}

Test(str_to_int, null_string)
{
    char *str = NULL;
    int nb = str_to_int(str);

    cr_assert(nb == -123, "Expected -123 but got %d\n", nb);
}

Test(int_to_str, simple_convertion)
{
    int nb = 642;
    char *str = int_to_str(nb);

    cr_assert_str_eq(str, "642");
}

Test(int_to_str, difficult_convertion)
{
    int nb = 1234567890;
    char *str = int_to_str(nb);

    cr_assert_str_eq(str, "1234567890");
}