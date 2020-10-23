/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int len = 0;
    int max = 0;

    while (dest[len] != '\0')
        len++;
    for (int k = 0; src[k] != '\0'; k++) {
        dest[len + k] = src[k];
        max++;
    }
    dest[len + max + 1] = '\0';
    return (dest);
}
