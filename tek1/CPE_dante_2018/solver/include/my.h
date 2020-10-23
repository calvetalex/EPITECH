/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib of prototypes
*/

#ifndef ERROR

static const int ERROR = 84;
static const int SUCCESS = 0;

//functions for project
char *get_next_line(int fd);

//functions in the lib
int my_getnbr(char const *str);
void my_putchar(char c);
int my_isneg(int n);
int putnbr(int nb);
int my_putstr(char const *str);
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

#endif
