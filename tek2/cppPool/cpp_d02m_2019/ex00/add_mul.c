/*
** EPITECH PROJECT, 2020
** add_mul
** File description:
** multiply params
*/

void add_mul_4param(int first , int  second , int *sum , int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first , int *second)
{
    *first += *second;
    *second = (*first - *second) * *second;
}