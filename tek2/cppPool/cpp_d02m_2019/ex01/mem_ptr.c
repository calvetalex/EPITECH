/*
** EPITECH PROJECT, 2020
** mem_ptr
** File description:
** pointer utilisation
*/

#include <string.h>
#include <stdlib.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;
    *res = malloc(sizeof(char) * (len1 + len2 + 1));
    strcat(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    int len1 = strlen(str_op->str1);
    int len2 = strlen(str_op->str2);
    int i = 0;
    str_op->res = malloc(sizeof(char) * (len1 + len2 + 1));
    strcat(str_op->res, str_op->str1);
    strcat(str_op->res, str_op->str2);

}