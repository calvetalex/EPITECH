/*
** EPITECH PROJECT, 2018
** step3.c
** File description:
** rush2
*/

char my_putchar(char c);

char my_putstr(char const *str);

int my_put_nbr(int nb);

void print(char const **av, int i, int nb, int res, int per)
{
    my_putstr(av[i]);
    my_putchar(':');
    my_put_nbr(nb);
    my_putchar('(');
    my_put_nbr(res);
    my_putchar('.');
    my_put_nbr(per);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

void percent(int ac, char const **av, int nb, int i)
{
    int len = 0;
    int k = 0;
    int res = 0;
    int per = 0;

    while (av[1][k] != '\0') {
        len++;
        k++;
    }
    res = nb * 100 / len;
    per = nb * 10000 / len % 100;
    print(av, i, nb, res, per);
}

int step3(int ac, char const **av)
{
    int nb = 0;
    int k = 0;
    int len = 0;

    for (int i = 2; i < ac; i++) {
        while (av[1][k] != '\0') {
            len = my_strlen(av[i][k]);
            if (len > 1)
                return (84);
            my_put_nbr(len);
            if (av[1][k] == av[i][0] || av[1][k] == (av[i][0] + 32)) {
                nb++;
            }
            k++;
        }
        percent(ac, av, nb, i);
        k = 0;
        nb = 0;
    }
}
