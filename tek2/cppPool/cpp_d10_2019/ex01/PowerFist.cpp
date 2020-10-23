/*
** EPITECH PROJECT, 2020
** PowerFist
** File description:
** PowerFist
*/

#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack(void) const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}