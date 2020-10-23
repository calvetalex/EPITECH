/*
** EPITECH PROJECT, 2020
** Fruit
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(const std::string& name, int16_t vitamins)
{
    this->_name = name;
    this->_vitamins = vitamins;
}

Fruit::~Fruit()
{
}

Fruit::Fruit(const Fruit &toCopy)
{
    this->_vitamins = toCopy.getVitamins();
    this->_name = toCopy.getName();
}

Fruit &Fruit::operator=(const Fruit&toAssign)
{
    this->_vitamins = toAssign.getVitamins();
    this->_name = toAssign.getName();
    return *this;
}

std::string Fruit::getName(void) const
{
    return this->_name;
}

int16_t Fruit::getVitamins(void) const
{
    return this->_vitamins;
}

void Fruit::setName(std::string &newName)
{
    this->_name = newName;
}

void Fruit::setVitamins(int16_t newVitamins)
{
    this->_vitamins = newVitamins;
}