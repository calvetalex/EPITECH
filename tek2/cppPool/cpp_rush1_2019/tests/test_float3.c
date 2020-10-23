/*
** EPITECH PROJECT, 2020
** test
** File description:
** test Float
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_float.h"
#include "criterion_new.h"

Test(Float_class, Float_eq_error)
{
    Object *v1 = new(Float , 4.0f);
    Object *v2 = new(Float , 2.0f);
    bool test = eq(v1 , v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}

Test(Float_class, Float_lt_error)
{
    Object *v1 = new(Float , 4.0f);
    Object *v2 = new(Float , 2.0f);
    bool test = lt(v1, v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}

Test(Float_class, Float_gt_error)
{
    Object *v1 = new(Float , 4.0f);
    Object *v2 = new(Float , 12.0f);
    bool test = gt(v1, v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}