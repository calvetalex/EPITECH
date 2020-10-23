/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** return 0 if a str is a nbr
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;
}
