/*
** EPITECH PROJECT, 2020
** Template
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template<typename Min>
const Min &min(const Min &a, const Min &b) {
    std::cout << "template min" << std::endl;
    return a <= b ? a : b;
}

int min(int a, int b) {
    std::cout << "non-template min" << std::endl;
    return a <= b ? a : b;
}

template<typename A>
A templateMin(const A *a, int size) {
    A m = a[0];
    for (int i = 1; i < size; i++)
        m = min<A>(m, a[i]);
    return m;
}

int nonTemplateMin(int *a, const int size) {
    int m = a[0];
    for (int i = 1; i < size; i++)
        m = min(m, a[i]);
    return m;
}

#endif /* !EX02_HPP_ */
