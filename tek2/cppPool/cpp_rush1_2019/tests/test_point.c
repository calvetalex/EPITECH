/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** test Point
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_point.h"
#include "criterion_new.h"

Test(Point_class, init_Point)
{
    Object *this = new(Point, 0, 1);
    cr_assert(((PointClass*)this)->x == 0);
    cr_assert(((PointClass*)this)->y == 1);
    delete(this);
}

Test(Point_class, Point_str)
{
    Object *this = new(Point, 0, 1);
    char * str = str(this);
    cr_assert_str_eq(str, "<Point (0, 1)>");
    delete(this);
    free(str);
}

Test(Point_class, Point_add)
{
    Object *v1 = new(Point , 1, 2);
    Object *v2 = new(Point , 4, 5);
    PointClass *test = addition(v1 , v2);
    cr_assert(((PointClass*)test)->x == 5);
    cr_assert(((PointClass*)test)->y == 7);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Point_class, Point_sum)
{
    Object *v1 = new(Point , 1, 2);
    Object *v2 = new(Point , 4, 5);
    PointClass *test = subtraction(v1, v2);
    cr_assert(((PointClass*)test)->x == -3);
    cr_assert(((PointClass*)test)->y == -3);
    delete(v1);
    delete(v2);
    delete(test);
}