/*
** EPITECH PROJECT, 2020
** Template
** File description:
** ex00
*/

#ifndef TEMPLATE_HPP_
#define TEMPLATE_HPP_

template<typename Swap>
void swap(Swap &a, Swap &b) {
    Swap tmp = a;
    a = b;
    b = tmp;
}

template<typename Min>
Min min(Min a, Min b) {
    return a < b ? a : b;
}

template<typename Max>
Max max(Max a, Max b) {
    return a > b ? a : b;
}

template<typename Add>
Add add(Add a, Add b) {
    return a + b;
}

#endif /* !EX00_HPP_ */
