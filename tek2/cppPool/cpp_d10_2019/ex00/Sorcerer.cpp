/*
** EPITECH PROJECT, 2020
** Sorcerer
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title)
{
    this->_name = name;
    this->_title = title;
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

void Sorcerer::polymorph(const Victim& victim) const
{
    victim.getPolymorphed();
}

std::ostream& operator<<(std::ostream &stream, Sorcerer const &toPrint)
{
    stream << "I am " << toPrint.getName() << ", " << toPrint.getTitle() << ", and I like ponies!" << std::endl;;
    return stream;
}