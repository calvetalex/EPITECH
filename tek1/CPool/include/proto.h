/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib of prototypes
*/

#include "struct.h"

#ifndef PROTO_H_
#define PROTO_H_

//functions for project

//functions in the lib
int my_getnbr(char const *str);
void my_putchar(char c);
int my_isneg(int n);
int putnbr(int nb);
int my_putstr(char const *str);
int my_puterr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
void my_swap(int a, int b);
int str_to_int(char *str);
int my_str_isnum(char const *str);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int my_show_word_array(char *const *tab);
char *my_strdup(char const *str);
int my_str_is_printable(char const *str);
char *my_strstr(char *str, char const *to_find);
char *strlower(char *str);
char **my_str_to_wa(char *str);
void free_array(char **str);
int tablen(char **tab);
char *int_to_str(int nbr);

#endif