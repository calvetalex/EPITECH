/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** find repet. between two strings
*/

char *my_strstr(char *str, char const *to_find)
{
    const char *p_to_find = to_find;
    char *point = str;

    while (*str || *str == '\0') {
        if (*p_to_find == '\0')
            return (point);
        else if (*p_to_find == *str) {
            p_to_find++;
            str++;
        } else {
            p_to_find = to_find;
            str++;
            point = str;
        }
    }
    return (0);
}
