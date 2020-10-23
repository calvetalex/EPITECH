/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** test Vertex
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "criterion.h"
#include "criterion_vertex.h"
#include "criterion_new.h"

Test(Vertex_class, init_Vertex)
{
    Object *this = new(Vertex, 0, 1, 2);
    cr_assert(((VertexClass*)this)->x == 0);
    cr_assert(((VertexClass*)this)->y == 1);
    cr_assert(((VertexClass*)this)->z == 2);
    delete(this);
}

Test(Vertex_class, Vertex_str)
{
    Object *this = new(Vertex, 0, 1, 2);
    char * str = str(this);
    cr_assert_str_eq(str, "<Vertex (0, 1, 2)>");
    delete(this);
    free(str);
}

Test(Vertex_class, Vertex_add)
{
    Object *v1 = new(Vertex , 1, 2, 3);
    Object *v2 = new(Vertex , 4, 5, 6);
    VertexClass *test = addition(v1 , v2);
    cr_assert(((VertexClass*)test)->x == 5);
    cr_assert(((VertexClass*)test)->y == 7);
    cr_assert(((VertexClass*)test)->z == 9);
    delete(v1);
    delete(v2);
    delete(test);
}

Test(Vertex_class, Vertex_sum)
{
    Object *v1 = new(Vertex , 1, 2, 3);
    Object *v2 = new(Vertex , 4, 5, 6);
    VertexClass *test = subtraction(v1, v2);
    cr_assert(((VertexClass*)test)->x == -3);
    cr_assert(((VertexClass*)test)->y == -3);
    cr_assert(((VertexClass*)test)->z == -3);
    delete(v1);
    delete(v2);
    delete(test);
}