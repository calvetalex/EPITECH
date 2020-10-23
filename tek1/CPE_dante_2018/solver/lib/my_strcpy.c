/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy a string in another
*/

char my_putchar(char c);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    char c = '\0';

    for (i = 0; src[i] != c; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
