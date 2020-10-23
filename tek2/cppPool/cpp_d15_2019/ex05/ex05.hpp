/*
** EPITECH PROJECT, 2020
** Template
** File description:
** ex05
*/

#ifndef EX05_HPP_
#define EX05_HPP_

template<typename T>
class array {
    array(unsigned int n = 0) {  };
    ~array();
    array(array &);
    array &operator=(const array &);
}

#endif /* !EX05_HPP_ */