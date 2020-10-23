/*
** EPITECH PROJECT, 2018
** str_to_int.c
** File description:
** push an str in a int
*/

int str_to_int(char *str)
{
    int res;

    for (int i = 0; str[i] != '\0'; i++)
        res = res * 10 + (str[i] - 48);
    return (res);
}
