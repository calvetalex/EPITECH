/*
** EPITECH PROJECT, 2018
** test my_strlen.c
** File description:
** TU for strlen function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "my.h"

Test(strlen_testing, classic_str)
{
    char *str = "This is a string.";
    int len = my_strlen(str);

    cr_assert(len == 17, "Expected 17 but got %d\n", len);
}

Test(strlen_testing, null_str)
{
    char *str = NULL;
    int len = my_strlen(str);

    cr_assert(len == -1, "Expected -1 but got %d\n", len);
}

Test(strlen_testing, long_str)
{
    char *str = "This is a string, a very long string. It s quit difficult to \
    find inspiration to make the test so i will just write random letters on \
    my keyboard: ajoisofoc isfsjfcmpjospj a awùa cjmaqùµ jaùù cm; a ;jsfhahnsmf\
     na a. I think it s OK.";
    int len = my_strlen(str);

    cr_assert(len == 249, "Expected 249 but got %d\n", len);
}