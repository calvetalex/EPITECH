/*
** EPITECH PROJECT, 2018
** mu_putstr.c
** File description:
** display string's char one by one
*/

char my_putchar(char c);

int my_putstr(char const *str)
{
    char a = *str;
    char c = '\0';

    while ( *str != c) {
        a = *str;
        my_putchar(a);
        str++;
    }
}
