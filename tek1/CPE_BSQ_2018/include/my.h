/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** lib of prototypes
*/

#ifndef HEADER_H_
#define HEADER_H_

static const int ERROR = 84;
static const int SUCCESS = 0;
static const char WALL = 'o';
static const char EMPTY = '.';
static const char BIGGEST = 'x';

typedef struct game_s {
    int beg_x;
    int beg_y;
    int max_x;
    int max_y;
    int max_size;
    char **map;
    int height;
    int width;
}game_t;

//functions for project
int verif_input(int ac, char **av);
int init_game(struct game_s *, char *);
void free_all(struct game_s *, char *);
int verif_map(game_t *info);
void find_bsq(game_t *info);

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
char *my_strdup(char const *str);
int my_str_is_printable(char const *str);
char *my_strstr(char *str, char const *to_find);
char *strlower(char *str);
char **str_to_word_array(char *str, char *sep);

#endif
