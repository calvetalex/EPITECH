/*
** EPITECH PROJECT, 2018
** step2.c
** File description:
** give the nb of occurences for n char
*/
char my_putchar(char c);
char my_putstr(char const *str);
int my_put_nbr(int nb);

int step2(int ac, char const **av)
{
    int nb = 0;
    int k = 0;

    for (int i = 2; i < ac; i++) { 
        while (av[1][k] != '\0') {
            if (av[1][k] == av[i][0] || av[1][k] == (av[i][0] + 32) ) {
                nb++;
            }
            k++;
        }
        my_putstr(av[i]);
        my_putchar(':');
        my_put_nbr(nb);
        my_putchar('\n');
        k = 0;
        nb = 0;
    }
}

void main(int ac, char const **av)
{
    step2(ac, av);
}
