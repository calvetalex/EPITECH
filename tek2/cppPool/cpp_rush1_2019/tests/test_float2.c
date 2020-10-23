/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** test Float
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_float.h"
#include "criterion_new.h"

Test(Float_class, Float_eq)
{
    Object *v1 = new(Float , 1.0f);
    Object *v2 = new(Float , 1.0f);
    bool test = eq(v1 , v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Float_class, Float_lt)
{
    Object *v1 = new(Float , 1.0f);
    Object *v2 = new(Float , 4.0f);
    bool test = lt(v1, v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Float_class, Float_gt)
{
    Object *v1 = new(Float , 4.0f);
    Object *v2 = new(Float , 1.0f);
    bool test = gt(v1, v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Float_class, Float_str)
{
    Object *v1 = new(Float , 49.0f);
    char *test = str(v1);
    cr_assert_str_eq(test, "<Float (49.000000)>");
    delete(v1);
    free(test);
}