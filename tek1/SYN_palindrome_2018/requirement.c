/*
** EPITECH PROJECT, 2018
** requirement.c
** File description:
** requirement for palindrome project
*/

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    nb = nb * my_factrec_synthesis(nb - 1);
    return (nb);
}

int my_squareroot_synthesis(int nb)
{
    int sqrt = 1;

    if (nb < 0)
        return (-1);
    if (nb == 0)
        return (0);
    if (nb == 1)
        return (1);
    for (;(sqrt * sqrt) <= nb; sqrt++)
        if ((sqrt * sqrt) == nb)
            return (sqrt);
    return (-1);
}