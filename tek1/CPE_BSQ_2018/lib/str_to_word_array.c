/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** convert a string to a string array
*/

#include <stdlib.h>

int my_strlen(const char *);

static int is_a_char(char c, char const *sep)
{
    for (int i = 0; sep[i] != 0; i++) {
        if (c == sep[i]) {
            return 0;
        }
    }
    return 1;
}

static int count_words(char *str, char *sep, int len)
{
    int res = 0;

    for (int i = 0, temp = 0; i < len;) {
        for (; !is_a_char(str[i], sep) && str[i] != '"' && i < len; i++);
        if ('"' == str[i]) {
            i++;
            for (temp = i; str[i] != '"' && i < len; i++);
            res = (i > temp)? res + 1 : res;
            i++;
        } else {
            for (temp = i; is_a_char(str[i], sep)
                && str[i] != '"' && i < len; i++);
            res = (i > temp)? res + 1 : res;
        }
    }
    return res;
}

static char **malloc_array(char *str, char *sep, int len, int nb_words)
{
    char **res = malloc(sizeof(char *) * (nb_words + 1));

    res[nb_words] = NULL;
    for (int i = 0, j = 0, c = 0; i < nb_words; i++, c = 0) {
        for (; !is_a_char(str[j], sep) && j < len && str[j] != '"'; j++);
        if ('"' == str[j]) {
            j++;
            for (; str[j] != '"' && j < len; j++, c++);
            j++;
        } else {
            for (; is_a_char(str[j], sep)
                && str[j] != '"' && j < len; j++, c++);
        }
        res[i] = malloc(sizeof(char) * (c + 1));
    }
    return res;
}

char **str_to_word_array(char *str, char *sep)
{
    int len = my_strlen(str);
    int nb_words = count_words(str, sep, len);
    char **res = malloc_array(str, sep, len, nb_words);

    for (int i = 0, j = 0; i < nb_words; i++) {
        for (; !is_a_char(str[j], sep) && j < len && str[j] != '"'; j++);
        if ('"' == str[j]) {
            j++;
            for (int c = 0; str[j] != '"' && j < len; j++, c++)
                res[i][c] = str[j];
            j++;
        } else {
            for (int c = 0; is_a_char(str[j], sep)
                && str[j] != '"' && j < len; j++, c++) {
                res[i][c] = str[j];
            }
        }
    }
    return res;
}