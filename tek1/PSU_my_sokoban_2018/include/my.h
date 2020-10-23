/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib of protypes
*/

#ifndef HEADER
# define HEADER

# define ERROR "error"
# define END 2

 //proto of sokoban functions

 int find_player(char *str);
 void move_right(char *str);
 void move_left(char *str);
 void move_up(char *str);
 void move_down(char *str);
 int my_popup(char *str, char *map);
 int my_strlen(char *str);
 int iswinup(char *str, int place, int line);
 int iswindown(char *str, int place, int line);
 int iswinright(char *str, int place);
 int iswinleft(char *str, int place);
 int my_strlen(char *str);
 int my_putnbr(int nb);
 void my_putchar(char c);
 int disp_use(void);
 int my_printf(char const *format, ...);

 //proto of lib
# include <stdarg.h>
 void my_putchar(char c);
 int my_getnbr(char const *str);
 int testing(long int n);
 void my_put_nbr(int nb);
 void my_putstr(char *str);
 char *my_revstr(char *str);
 char my_strcat(char *dest, char const *src);
 int my_strcmp(char const *str1, char const *str2);
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
void disp_unsigned(unsigned int nb);

#endif
