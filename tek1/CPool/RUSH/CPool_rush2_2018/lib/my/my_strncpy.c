/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** copy n char from a string to another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int c = 0;

    while (src[c] != '\0') {
        c++;
    }
    for (int i = 0; i <= n; i++)
        dest[i] = src[i];
    if (n > c)
        for (c; c < n; c++)
            dest[c] = '\0';
}
