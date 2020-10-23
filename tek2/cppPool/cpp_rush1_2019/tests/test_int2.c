/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** test Int
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_int.h"
#include "criterion_new.h"

Test(Int_class, Int_eq)
{
    Object *v1 = new(Int , 1);
    Object *v2 = new(Int , 1);
    bool test = eq(v1 , v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Int_class, Int_lt)
{
    Object *v1 = new(Int , 1);
    Object *v2 = new(Int , 4);
    bool test = lt(v1, v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Int_class, Int_gt)
{
    Object *v1 = new(Int , 4);
    Object *v2 = new(Int , 1);
    bool test = gt(v1, v2);
    cr_assert(test == true);
    delete(v1);
    delete(v2);
}

Test(Int_class, Int_str)
{
    Object *v1 = new(Int , 1);
    char *test = str(v1);
    cr_assert_str_eq(test, "<Int (1)>");
    delete(v1);
    free(test);
}