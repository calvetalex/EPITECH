/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** compare two strings and return 0 is they are eguals
*/

int my_strcmp(char const *str1, char const *str2)
{
    int i;
    int j;

    while (*str1 == *str2 && *str1 != '\0') {
        i++;
        j++;
        str1++;
        str2++;
    }
    i = *str1;
    j = *str2;
    if (i < j)
        return (-1);
    else if (i == j)
        return (0);
    else
        return (1);
}
