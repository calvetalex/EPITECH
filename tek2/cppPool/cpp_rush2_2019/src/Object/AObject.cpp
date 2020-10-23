/*
** EPITECH PROJECT, 2020
** AObject
** File description:
** AObject
*/

#include "Object/AObject.hpp"

AObject::AObject(IObject::Type type)
{
    this->_typeObj = type;
}

AObject::~AObject()
{
}

const IObject::Type AObject::getType(void) const
{
    return this->_typeObj;
}
