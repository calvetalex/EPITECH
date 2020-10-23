/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** find the first nbr in a string
*/

int my_putchar(char c);

int my_getnbr(char const *str)
{
    int c = 0;
    int m = 0;
    int taillnb = 0;
    int nb;

    while (str[c] != '\0') {
        if (str[c] == '-')
            m++;
        if (str[c] >= '0' && str[c] <= '9') {
            nb = nb * 10 + (str[c] - 48);
            taillnb++;
        } else if (taillnb > 0)
            break;
        c++;
    }
    if ((m % 2) == 1)
        nb = -1 * nb;
    return (nb);
}
