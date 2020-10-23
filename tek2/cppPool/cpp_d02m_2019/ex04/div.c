/*
** EPITECH PROJECT, 2020
** castmania
** File description:
** divisions
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a/b);
}

float decimale_div(int a, int b)
{
    float res = 0;

    if (b == 0)
        return (0);
    res = (float)a / (float)b;
    return (res);
}

void  exec_div(division_t *operation)
{
    if (operation->div_type == DECIMALE)
        ((decimale_op_t*) operation->div_op)->res = decimale_div(
            ((decimale_op_t*) operation->div_op)->a,
            ((decimale_op_t*) operation->div_op)->b);
    else
        ((integer_op_t*) operation->div_op)->res = integer_div(
            ((integer_op_t*) operation->div_op)->a,
            ((integer_op_t*) operation->div_op)->b);

}