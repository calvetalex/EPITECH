/*
** EPITECH PROJECT, 2020
** Parts
** File description:
** Parts
*/

#include <iostream>
#include <iomanip>
#include "Parts.hpp"

// ARMS

Arms::Arms(std::string serial, bool status): _serial(serial), _isFunctionnal(status)
{
}

Arms::~Arms()
{
}

bool Arms::isFunctionnal() const
{
    return this->_isFunctionnal;
}

std::string Arms::serial() const
{
    return this->_serial;
}

void Arms::informations() const
{
    std::string status = this->_isFunctionnal == true ? "OK" : "KO";
    std::cout << "     [Parts] Arms " << this->_serial << " status : " << status << std::endl;
}

// LEGS

Legs::Legs(std::string serial, bool status) : _serial(serial), _isFunctionnal(status)
{
}

Legs::~Legs()
{
}

bool Legs::isFunctionnal() const
{
    return this->_isFunctionnal;
}

std::string Legs::serial() const
{
    return this->_serial;
}

void Legs::informations() const
{
    std::string status = this->_isFunctionnal == true ? "OK" : "KO";
    std::cout << "     [Parts] Legs " << this->_serial << " status : " << status << std::endl;
}

// HEAD

Head::Head(std::string serial, bool status) : _serial(serial), _isFunctionnal(status)
{
}

Head::~Head()
{
}

bool Head::isFunctionnal() const
{
    return this->_isFunctionnal;
}

std::string Head::serial() const
{
    return this->_serial;
}

void Head::informations() const
{
    std::string status = this->_isFunctionnal == true ? "OK" : "KO";
    std::cout << "     [Parts] Head " << _serial << " status : " << status << std::endl;
}