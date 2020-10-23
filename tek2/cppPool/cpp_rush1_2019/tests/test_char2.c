/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** test Char
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_char.h"
#include "criterion_new.h"

Test(Char_class, Char_eq)
{
    Object *v1 = new(Char , 1);
    Object *v2 = new(Char , 1);
    bool test = eq(v1 , v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Char_class, Char_lt)
{
    Object *v1 = new(Char , 1);
    Object *v2 = new(Char , 4);
    bool test = lt(v1, v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Char_class, Char_gt)
{
    Object *v1 = new(Char , 4);
    Object *v2 = new(Char , 1);
    bool test = gt(v1, v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Char_class, Char_str)
{
    Object *v1 = new(Char , 49);
    char *test = str(v1);
    cr_assert_str_eq(test, "<Char (1)>");
    delete(v1);
    free(test);
}