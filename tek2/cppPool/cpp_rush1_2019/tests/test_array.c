/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** array
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_array.h"
#include "criterion_int.h"
#include "criterion_new.h"

Test(array, functional_test)
{
    Object  *array = new(Array, 10, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = end(array);

    setitem(array, 5, 12);
    while (lt(it, it_end))
    {
        IntClass *test = getval(it);
        if (((ArrayIteratorClass *)it)->_idx != 5)
            cr_assert_eq(test->value, 0);
        else
            cr_assert_eq(test->value, 12);
        delete(test);
        incr(it);
    }
    delete(it);
    delete(it_end);
}