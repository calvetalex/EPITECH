/*
** EPITECH PROJECT, 2020
** func_ptr
** File description:
** pointers on different functions
*/

#include <stdio.h>
#include <string.h>
#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int len = strlen(str) - 1;
    while (len > -1) {
        printf("%c", str[len]);
        len--;
    }
    printf("\n");
}

void print_upper(const char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    printf("\n");
}

void print_42(const char *str)
{
    if (str)
        printf("42\n");
}

void  do_action(action_t  action , const  char *str)
{
    const tab_pointeur_t tab_point[] = {
        {PRINT_NORMAL, &print_normal},
        {PRINT_REVERSE, &print_reverse},
        {PRINT_UPPER, &print_upper},
        {PRINT_42, &print_42},
    };

    for (int i = 0; i < 4; i++) {
        if (tab_point[i].str == action) {
            tab_point[i].redir(str);
        }
    }
}