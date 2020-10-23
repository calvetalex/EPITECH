/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reverse a string
*/

char my_putchar(char c);

char *my_revstr(char *str)
{
    int c = 0;
    char save;

    while (str[c] != '\0') {
        c++;
    }
    for (int t = 0; t < (c / 2); t++) {
        save = str[t];
        str[t] = str[c - 1 - t];
        str[c - 1- t] = save;
    }
    return (str);
}
