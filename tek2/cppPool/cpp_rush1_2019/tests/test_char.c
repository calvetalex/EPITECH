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

Test(Char_class, init_Char)
{
    Object *this = new(Char, 12);
    cr_assert(((CharClass*)this)->value == 12);
    delete(this);
}

Test(Char_class, Char_add)
{
    Object *v1 = new(Char , 1);
    Object *v2 = new(Char , 4);
    CharClass *test = addition(v1 , v2);
    cr_assert(((CharClass*)test)->value == 5);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Char_class, Char_sum)
{
    Object *v1 = new(Char , 1);
    Object *v2 = new(Char , 4);
    CharClass *test = subtraction(v1, v2);
    cr_assert(((CharClass*)test)->value == -3);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Char_class, Char_div)
{
    Object *v1 = new(Char , 12);
    Object *v2 = new(Char , 4);
    CharClass *test = division(v1, v2);
    cr_assert(((CharClass*)test)->value == 3);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Char_class, Char_mul)
{
    Object *v1 = new(Char , 1);
    Object *v2 = new(Char , 4);
    CharClass *test = multiplication(v1, v2);
    cr_assert(((CharClass*)test)->value == 4);
    delete(v1);
    delete(v2);
    delete(test);
}