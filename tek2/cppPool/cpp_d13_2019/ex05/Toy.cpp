/*
** EPITECH PROJECT, 2020
** Toy
** File description:
** Toy
*/

#include <iostream>
#include "Toy.hpp"

Toy::Toy()
{
    this->_name = "toy";
    this->_type = ToyType::BASIC_TOY;
    this->_picture = Picture("");
    this->_error.type = Error::ErrorType::UNKNOWN;
}

Toy::Error::Error(): type(ErrorType::UNKNOWN)
{
}

Toy::~Toy()
{
}

Toy::Toy(Toy &toCopy)
{
    this->_name = toCopy.getName();
    this->_type = toCopy.getType();
    this->_picture = toCopy.getAscii();
    this->_error = toCopy.getError();
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

Toy::Error Toy::getError(void) const
{
    return (this->_error);
}

void Toy::setName(const std::string &name)
{
    this->_name = name;
}

bool Toy::setAscii(const std::string &fileName)
{
    this->_picture = Picture(fileName);
    if (this->_picture.getData() == "ERROR" || this->_picture.getData().empty()) {
        this->_error.type = Error::ErrorType::PICTURE;
        return false;
    }
    return true;
}

void Toy::speak(const std::string&toSay)
{
    std::cout << this->_name << " \"" << toSay << "\"" << std::endl;
}

bool Toy::speak_es(const std::string&toSay)
{
    (void)toSay;
    this->_error.type = Error::ErrorType::SPEAK;
    return false;
}

std::ostream &operator<<(std::ostream &stream, const Toy& toPrint)
{
    stream << toPrint.getName() << std::endl << toPrint.getAscii() << std::endl;
    return stream;
}

Toy &Toy::operator<<(const std::string& newAscii)
{
    this->_picture.setData(newAscii);
    return *this;
}

Toy::Error Toy::getLastError(void)
{
    return this->_error;
}

std::string Toy::Error::what(void) const
{
    if (this->type == ErrorType::PICTURE)
        return "bad new illustration";
    if (this->type == ErrorType::SPEAK)
        return "wrong mode";
    return "";
}

std::string Toy::Error::where(void) const
{
    if (this->type == ErrorType::PICTURE)
        return "setAscii";
    if (this->type == ErrorType::SPEAK)
        return "speak_es";
    return "";
}