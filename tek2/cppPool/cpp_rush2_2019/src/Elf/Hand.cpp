/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#include "Elf/Hand.hpp"

Hand::Hand()
{
    this->_carriedObject = nullptr;
}

Hand::~Hand()
{
}

const bool Hand::isUsed(void) const
{
    if (_carriedObject == nullptr)
        return (false);
    else
        return (true);
}

void Hand::setObject(AObject *obj)
{
    _carriedObject = obj;
}

AObject *Hand::getObject(void)
{
    AObject *tmp = _carriedObject;
    _carriedObject = nullptr;
    return tmp;
}