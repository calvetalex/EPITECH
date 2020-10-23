/*
** EPITECH PROJECT, 2018
** test_str_isnum.c
** File description:
** testing of str_is_num function
*/

#include <criterion/criterion.h>
#include "my.h"

Test(str_isnum, str_isnum_good)
{
    char *str = "363";
    int res = my_str_isnum(str);

    cr_assert(res == 0, "Expected 0 but got %d\n", res);
}

Test(str_isnum, str_not_num)
{
    char *str = "word";
    int res = my_str_isnum(str);

    cr_assert(res == 1, "Expected 1 but got %d\n", res);
}
