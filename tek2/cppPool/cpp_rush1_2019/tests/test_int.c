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

Test(Int_class, init_Int)
{
    Object *this = new(Int, 12);
    cr_assert(((IntClass*)this)->value == 12);
    delete(this);
}

Test(Int_class, Int_add)
{
    Object *v1 = new(Int , 1);
    Object *v2 = new(Int , 4);
    IntClass *test = addition(v1 , v2);
    cr_assert(((IntClass*)test)->value == 5, "%d\n", ((IntClass*)test)->value);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Int_class, Int_sum)
{
    Object *v1 = new(Int , 1);
    Object *v2 = new(Int , 4);
    IntClass *test = subtraction(v1, v2);
    cr_assert(((IntClass*)test)->value == -3, "%d\n", ((IntClass*)test)->value);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Int_class, Int_div)
{
    Object *v1 = new(Int , 12);
    Object *v2 = new(Int , 4);
    IntClass *test = division(v1, v2);
    cr_assert(((IntClass*)test)->value == 3, "%d\n", ((IntClass*)test)->value);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Int_class, Int_mul)
{
    Object *v1 = new(Int , 1);
    Object *v2 = new(Int , 4);
    IntClass *test = multiplication(v1, v2);
    cr_assert(((IntClass*)test)->value == 4, "%d\n", ((IntClass*)test)->value);
    delete(v1);
    delete(v2);
    delete(test);
}