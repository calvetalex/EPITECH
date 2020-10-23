/*
** EPITECH PROJECT, 2020
** PEON
** File description:
** Peon
*/

#include <iostream>
#include "Peon.hpp"

Peon::Peon(const std::string &name): Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed(void) const
{
    std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}