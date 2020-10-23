/*
** EPITECH PROJECT, 2018
** my_str_isprintable.c
** File description:
** return 0 if str is printable
*/

int my_str_isprintable(char const *str)
{
    while (*str != '\0') {
        if (*str < 32 || *str > 126)
            return (1);
    }
    return (0);
}
