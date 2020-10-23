/*
** EPITECH PROJECT, 2020
** fun_ptr
** File description:
** header file
*/

#ifndef FUNC_PTR_H_
#define FUNC_PTR_H_

#include "func_ptr_enum.h"

typedef struct pointer_s {
    action_t str;
    void (*redir)();
} tab_pointeur_t;

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);

#endif /* !FUNC_PTR_H_ */
