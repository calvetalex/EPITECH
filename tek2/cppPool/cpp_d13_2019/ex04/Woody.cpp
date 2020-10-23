/*
** EPITECH PROJECT, 2020
** Woody
** File description:
** Woody
*/

#include <iostream>
#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file): Toy(ToyType::WOODY, name, file)
{
}

Woody::~Woody()
{
}

Woody &Woody::operator=(Woody &toAssign)
{
    this->_type = toAssign.getType();
    this->_name = toAssign.getName();
    this->_picture = toAssign.getAscii();
    return *this;
}

void Woody::speak(const std::string&toSay)
{
    std::cout << "WOODY: " << this->_name << " \"" << toSay << "\"" << std::endl;
}