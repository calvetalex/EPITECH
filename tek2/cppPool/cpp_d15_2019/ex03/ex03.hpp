/*
** EPITECH PROJECT, 2020
** Template
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template<typename T>
void foreach(const T *a, void func(const T&), int size) {
    for (int i = 0; i < size; i++)
        func(a[i]);
}

template<typename T>
void print(const T&elem) {
    std::cout << elem << std::endl;
}

#endif /* !EX03_HPP_ */
