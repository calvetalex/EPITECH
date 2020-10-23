/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** Teddy
*/

#include <iostream>
#include "Object/AObject.hpp"
#include "Object/Toy/Teddy.hpp"

Teddy::Teddy(Type typeObject,
            const std::string &title) : IToy(typeObject)
{
    this->_title = title;
    pickUp = false;
}

Teddy::Teddy(Teddy &cpy) : IToy(cpy._typeObj)
{
    this->_title = cpy._title;
    pickUp = cpy.pickUp;
}

Teddy::~Teddy()
{
}

const bool Teddy::isTaken(void)
{
    pickUp = !pickUp;
    if (pickUp)
        std::cout << "grah hu" << std::endl;
    return pickUp;
}

const std::string &Teddy::getTitle(void) const
{
    return (_title);
}
