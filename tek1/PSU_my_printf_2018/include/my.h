/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib of prototypes
*/
#include <stdarg.h>
void my_putchar(char c);
int my_getnbr(char const *str);
int testing(long int n);
void my_put_nbr(int nb);
void my_putstr(char *str);
char *my_revstr(char *str);
char my_strcat(char *dest, char const *src);
int my_strcmp(char const *str1, char const *str2);
int my_strlen(char const *str);
void my_swap(int *a, int *b);
int sum_stdarg(int i, int nb, ...);
void disp_stdarg(char s, va_list *ap);
int my_printf(const char *format, ...);
void disp_binary(long int nb);
void disp_hexamin(int nb);
void disp_hexamaj(int nb);
void disp_oct(int nb);
void disp_membase(long unsigned int nb);
void disp_nonprintable(char *str);
