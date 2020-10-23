/*
** EPITECH PROJECT, 2020
** Buzz
** File description:
** Buzz
*/

#include <iostream>
#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file): Toy(ToyType::BUZZ, name, file)
{
}

Buzz::~Buzz()
{
}

Buzz &Buzz::operator=(Buzz &toAssign)
{
    this->_type = toAssign.getType();
    this->_name = toAssign.getName();
    this->_picture = toAssign.getAscii();
    return *this;
}

void Buzz::speak(const std::string &toSay)
{
    std::cout << "BUZZ: " << this->_name << "\"" << toSay << "\"" << std::endl;
}

bool Buzz::speak_es(const std::string &toSay)
{
    std::cout << "BUZZ: " << this->_name << " senorita \"" << toSay << "\" senorita" << std::endl;
    return true;
}