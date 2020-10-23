/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** display a number
*/

void my_putchar(char c);

int putnbr(int nb)
{
    int nbr = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10)
        putnbr((nb/10));
    nbr = nb % 10 + '0';
    my_putchar(nbr);
    return 0;
}
