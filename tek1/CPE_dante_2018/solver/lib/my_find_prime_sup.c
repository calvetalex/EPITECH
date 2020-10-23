/*
** EPITECH PROJECT, 2018
** my_find_prime_sup.c
** File description:
** find the first prim nbr after the one which was given
*/

int my_prime(int nb)
{
    int i = 5;

    if (nb <= 3) {
        if (nb <= 1)
            return (0);
        else
            return (1);
    } else if (nb % 2 == 0 || nb % 3 == 0)
        return (0);
    while (i * i <= nb) {
        if (nb % i == 0 || nb % (i + 2) == 0)
            return (0);
        i = i + 6;
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int res = nb;
    int c = 0;

    while (c == 0) {
        c = my_prime(res);
        res++;
    }
    return (res - 1);
}
