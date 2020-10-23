/*
** EPITECH PROJECT, 2020
** conversion
** File description:
** main function
*/

#include <iostream>
#include "conversion.hpp"

int main(void)
{
    double temp;
    std::string base;

    std::cin >> temp >> base;
    return (base == "Celsius" ? convert_to_fahr(temp) : convert_to_cels(temp));
}