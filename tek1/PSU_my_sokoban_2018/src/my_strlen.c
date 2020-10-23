/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** return lenght of a str
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
