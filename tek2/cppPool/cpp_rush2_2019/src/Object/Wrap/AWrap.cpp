/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** AWrap
*/

#include "Object/Wrap/AWrap.hpp"

AWrap::AWrap()
{
    _isEmpty = true;
    _isOpen = false;
}

AWrap::~AWrap()
{
}

void AWrap::closeMe(void)
{
    this->_isOpen = false;
}

void AWrap::openMe(void)
{
    this->_isOpen = true;
}

void AWrap::setEmpty(bool value)
{
    this->_isEmpty = value;
}

void AWrap::setOpen(bool value)
{
    this->_isOpen = value;
}

const bool AWrap::getEmpty() const
{
    return _isEmpty;
}

const bool AWrap::getOpen() const
{
    return _isOpen;
}