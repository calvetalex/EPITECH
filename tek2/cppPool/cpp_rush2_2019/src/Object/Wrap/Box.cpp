/*
** EPITECH PROJECT, 2020
** Box
** File description:
** Box
*/

#include "Object/Wrap/Box.hpp"

Box::Box(Type type) : AWrap()
{
    this->_typeObj = type;
}

Box::Box(Box &cpy) : AWrap()
{
    this->_typeObj = cpy._typeObj;
}

Box::~Box()
{
}

AObject *Box::takeOff(void) const
{
    return (AObject *)this->_toyInside;
}

void Box::wrapMeThat(AObject *newToy)
{
    this->_toyInside = (AObject *)newToy;
}