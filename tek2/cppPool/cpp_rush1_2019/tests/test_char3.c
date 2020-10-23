/*
** EPITECH PROJECT, 2020
** test
** File description:
** test Char
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_char.h"
#include "criterion_new.h"

Test(Char_class, Char_eq_error)
{
    Object *v1 = new(Char , 4);
    Object *v2 = new(Char , 2);
    bool test = eq(v1 , v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}

Test(Char_class, Char_lt_error)
{
    Object *v1 = new(Char , 4);
    Object *v2 = new(Char , 2);
    bool test = lt(v1, v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}

Test(Char_class, Char_gt_error)
{
    Object *v1 = new(Char , 4);
    Object *v2 = new(Char , 12);
    bool test = gt(v1, v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}