/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for the generator
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (ERROR);
    if (my_str_isnum(av[1]) != 0 || my_str_isnum(av[2]) != 0)
        return (ERROR);
    if (str_to_int(av[1]) < str_to_int(av[2]))
        return (ERROR);
    if (ac == 4)
        if (my_strcmp(av[3], "perfect") != 0)
            return ERROR;
    switch (ac) {
        case 3:
            imperfect(str_to_int(av[1]), str_to_int(av[2]));
            break;
        case 4:
            perfect(str_to_int(av[1]), str_to_int(av[2]));
            break;
    }
    return (SUCCESS);
}