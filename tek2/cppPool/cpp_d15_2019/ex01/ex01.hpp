/*
** EPITECH PROJECT, 2020
** Template
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <cstring>

template<typename Cmp>
int compare(const Cmp &a, const Cmp &b) {
    if (a == b)
        return 0;
    return a > b ? 1 : -1;
}

int compare(const char *a, const char *b) {
    return strcmp(a, b) == 0 ? 0 : strcmp(a, b) > 0 ? 1 : -1;
}


#endif /* !EX01_HPP_ */