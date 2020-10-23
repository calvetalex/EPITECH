/*
** EPITECH PROJECT, 2020
** Toy
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    this->_name = "toy";
    this->_type = ToyType::BASIC_TOY;
    this->_picture = Picture("");
}

Toy::~Toy()
{
}

Toy::Toy(Toy &toCopy)
{
    this->_name = toCopy.getName();
    this->_type = toCopy.getType();
    this->_picture = toCopy.getAscii();
}

Toy::Toy(ToyType type, const std::string &name, const std::string &file)
{
    this->_name = name;
    this->_type = type;
    this->_picture = Picture(file);
}

Toy &Toy::operator=(const Toy& toAssign)
{
    this->_name = toAssign.getName();
    this->_type = toAssign.getType();
    this->_picture = toAssign.getAscii();
    return *this;
}

const std::string Toy::getName(void) const
{
    return this->_name;
}

Toy::ToyType Toy::getType(void) const
{
    return this->_type;
}

const std::string Toy::getAscii(void) const
{
    return this->_picture.getData();
}

void Toy::setName(const std::string &name)
{
    this->_name = name;
}

bool Toy::setAscii(const std::string &fileName)
{
    this->_picture = Picture(fileName);
    if (this->_picture.getData().empty())
        return false;
    return true;
}