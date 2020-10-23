/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** compare n char of two strings
*/
int my_strncmp(char const *str1, char const *str2, int n)
{
    int i;
    int j;
    int m = 0;

    while (*str1 == *str2 && *str1 != '\0' && m < n) {
        i++;
        j++;
        str1++;
        str2++;
        m++;
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
