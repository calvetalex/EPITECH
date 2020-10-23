/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** LittlePony.cpp
*/

#include <iostream>
#include "Object/AObject.hpp"
#include "Object/Toy/LittlePony.hpp"

LittlePony::LittlePony(Type typeObject,
                    const std::string &title) : IToy(typeObject)
{
    this->_title = title;
    pickUp = false;
}

LittlePony::LittlePony(LittlePony &cpy) : IToy(cpy._typeObj)
{
    this->_title = cpy._title;
    pickUp = cpy.pickUp;
}

LittlePony::~LittlePony()
{
}

const bool LittlePony::isTaken(void)
{
    pickUp = !pickUp;
    if (pickUp)
        std::cout << "yo man" << std::endl;
    return pickUp;
}

const std::string &LittlePony::getTitle(void) const
{
    return (_title);
}
