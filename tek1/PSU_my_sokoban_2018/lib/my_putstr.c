/*
** EPITECH PROJECT, 2018
** mu_putstr.c
** File description:
** display string's char one by one
*/
char my_putchar(char c);

void my_putstr(char *str)
{
    char a = *str;
    char c = '\0';

    while ( *str != c) {
        a = *str;
        my_putchar(a);
        str++;
    }
}
