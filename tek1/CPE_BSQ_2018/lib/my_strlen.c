/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** display the numbers of char in a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        i++;
        str++;
    }
    return (i);
}
