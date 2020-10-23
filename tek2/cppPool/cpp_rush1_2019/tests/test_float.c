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

Test(Float_class, init_Float)
{
    Object *this = new(Float, 12.0f);
    cr_assert(((FloatClass*)this)->value == 12.0f);
    delete(this);
}

Test(Float_class, Float_add)
{
    Object *v1 = new(Float , 1.0f);
    Object *v2 = new(Float , 4.0f);
    FloatClass *test = addition(v1 , v2);
    cr_assert(((FloatClass*)test)->value == 5);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Float_class, Float_sum)
{
    Object *v1 = new(Float , 1.0f);
    Object *v2 = new(Float , 4.0f);
    FloatClass *test = subtraction(v1, v2);
    cr_assert(((FloatClass*)test)->value == -3);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Float_class, Float_div)
{
    Object *v1 = new(Float , 12.0f);
    Object *v2 = new(Float , 4.0f);
    FloatClass *test = division(v1, v2);
    cr_assert(((FloatClass*)test)->value == 3);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Float_class, Float_mul)
{
    Object *v1 = new(Float , 1.0f);
    Object *v2 = new(Float , 4.0f);
    FloatClass *test = multiplication(v1, v2);
    cr_assert(((FloatClass*)test)->value == 4);
    delete(v1);
    delete(v2);
    delete(test);
}