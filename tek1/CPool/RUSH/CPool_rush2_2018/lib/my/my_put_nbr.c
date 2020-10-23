/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** function print for numbers with just my_putchar
*/

char my_putchar(char c);

int testing(long int n)
{
    if (n == 0) {
        my_putchar('0');
        return (0);
    }
}

int my_put_nbr(int nb)
{
    int a = 0;
    long int b = nb;
    int i = 1;
    int d = 1000000000;

    testing(b);
    if (b < 0) {
        b = -1 * b;
        my_putchar('-');
    }
    for (i ; i < 11 ; i++) {
        if ((b / d) >= 1) {
            a = (b / d) % 10 + 48;
        }
        d = d / 10;
        my_putchar(a);
    }
}
