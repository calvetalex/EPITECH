/*
** EPITECH PROJECT, 2020
** test
** File description:
** test int
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_int.h"
#include "criterion_new.h"

Test(Int_class, Int_eq_error)
{
    Object *v1 = new(Int , 4);
    Object *v2 = new(Int , 2);
    bool test = eq(v1 , v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}

Test(Int_class, Int_lt_error)
{
    Object *v1 = new(Int , 4);
    Object *v2 = new(Int , 2);
    bool test = lt(v1, v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}

Test(Int_class, Int_gt_error)
{
    Object *v1 = new(Int , 4);
    Object *v2 = new(Int , 12);
    bool test = gt(v1, v2);
    cr_assert(test == false);
    delete(v1);
    delete(v2);
}