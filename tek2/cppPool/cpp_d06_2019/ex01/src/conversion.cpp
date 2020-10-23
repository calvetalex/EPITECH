/*
** EPITECH PROJECT, 2020
** conversion
** File description:
** conversion functions
*/

#include <iostream>
#include <iomanip>

int convert_to_cels(double temp)
{
    double converted;

    converted = 5.0 / 9.0 * (temp - 32);
    std::cout.precision(3);
    std::cout << std::setw(16) << std::fixed << converted << std::setw(16) << "Celsius" << std::endl;
    return (0);
}

int convert_to_fahr(double temp)
{
    double converted;

    converted = temp * 9 / 5 + 32;
    std::cout.precision(3);
    std::cout << std::setw(16) << std::fixed << converted << std::setw(16) << "Fahrenheit" << std::endl;
    return (0);
}