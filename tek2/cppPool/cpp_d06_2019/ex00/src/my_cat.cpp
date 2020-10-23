/*
** EPITECH PROJECT, 2020
** my_cat
** File description:
** cat function
*/

#include <iostream>
#include <fstream>

static int disp_file(char *name)
{
    int err = 0;
    std::ifstream file(name);
    if (!file) {
        std::cerr << "my_cat: " << name << ": No such file or directory" << std::endl;
        err++;
    } else
        std::cout << file.rdbuf();
    return err;
}

int my_cat(char **argv)
{
    int err = 0;

    for (int size = 1; argv[size]; size++) {
        err += disp_file(argv[size]);
    }
    return (err);
}