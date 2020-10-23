/*
** EPITECH PROJECT, 2020
** VICTIM
** File description:
** Victim
*/

#include <iostream>
#include "Victim.hpp"

Victim::Victim(const std::string &name)
{
    this->_name = name;
    std::cout << "Some random victim called " << name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

void Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream& operator<<(std::ostream &stream, const Victim& victim)
{
    std::cout << "I'm " << victim.getName() << " and I like otters!" << std::endl;
    return stream;
}