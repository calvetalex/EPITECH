/*
** EPITECH PROJECT, 2020
** my_cat
** File description:
** main_function
*/

#include <iostream>
#include "my_cat.hpp"

int main(int ac, char **av)
{
    int err = 0;

    if (ac < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (84);
    }
    err = my_cat(av);
    return (err == 0 ? 0 : 84);
}