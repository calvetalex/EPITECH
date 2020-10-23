/*
** EPITECH PROJECT, 2019
** requirement.c
** File description:
** convert a string to a string array
*/

#include <stdlib.h>

static int my_str_len(char *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return (len);
}

static int is_a_char(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

static int count_words(char *str, int len)
{
    int res = 0;

    for (int i = 0, temp = 0; i < len;) {
        for (; !is_a_char(str[i]) && str[i] != '"' && i < len; i++);
        if ('"' == str[i]) {
            i++;
            for (temp = i; str[i] != '"' && i < len; i++);
            res = (i > temp)? res + 1 : res;
            i++;
        } else {
            for (temp = i; is_a_char(str[i])
                && str[i] != '"' && i < len; i++);
            res = (i > temp)? res + 1 : res;
        }
    }
    return res;
}

static char **malloc_array(char *str, int len, int nb_words)
{
    char **res = malloc(sizeof(char *) * (nb_words + 1));

    res[nb_words] = NULL;
    for (int i = 0, j = 0, c = 0; i < nb_words; i++, c = 0) {
        for (; !is_a_char(str[j]) && j < len && str[j] != '"'; j++);
        if ('"' == str[j]) {
            j++;
            for (; str[j] != '"' && j < len; j++, c++);
            j++;
        } else {
            for (; is_a_char(str[j])
                && str[j] != '"' && j < len; j++, c++);
        }
        res[i] = malloc(sizeof(char) * (c + 1));
        res[i][c] = '\0';
    }
    return res;
}

char **my_str_to_wa(char *str)
{
    int len = my_str_len(str);
    int nb_words = count_words(str, len);
    char **res = malloc_array(str, len, nb_words);

    for (int i = 0, j = 0; i < nb_words; i++) {
        for (; !is_a_char(str[j]) && j < len && str[j] != '"'; j++);
        if ('"' == str[j]) {
            j++;
            for (int c = 0; str[j] != '"' && j < len; j++, c++)
                res[i][c] = str[j];
            j++;
        } else {
            for (int c = 0; is_a_char(str[j])
                && str[j] != '"' && j < len; j++, c++) {
                res[i][c] = str[j];
            }
        }
    }
    return res;
}