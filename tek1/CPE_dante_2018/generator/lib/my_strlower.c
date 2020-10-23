/*
** EPITECH PROJECT, 2019
** my_strlower.c
** File description:
** change a str in a str in lowercase
*/

char *strlower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return (str);
}
