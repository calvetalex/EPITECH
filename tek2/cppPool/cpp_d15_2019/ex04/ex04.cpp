/*
** EPITECH PROJECT, 2020
** Template
** File description:
** ex04
*/

#include <string>
#include "ex04.hpp"

template<typename T> bool Tester<T>::equal(const T& a, const T&b) {
    return a == b;
}

template <> bool Tester<int>::equal(const int& a, const int&b) {
    return a == b;
}

template <> bool Tester<float>::equal(const float& a, const float&b) {
    return a == b;
}

template <> bool Tester<double>::equal(const double& a, const double&b) {
    return a == b;
}

template <> bool Tester<std::string>::equal(const std::string& a, const std::string&b) {
    return a.compare(b) == 0;
}

template<typename T> bool equal(const T&a, const T&b) {
    return a == b;
}

template <> bool equal(const int &a, const int &b) {
    return a == b;
}

template <> bool equal(const float &a, const float &b) {
    return a == b;
}

template <> bool equal(const double &a, const double &b) {
    return a == b;
}

template <> bool equal(const std::string &a, const std::string &b) {
    return a.compare(b) == 0;
}