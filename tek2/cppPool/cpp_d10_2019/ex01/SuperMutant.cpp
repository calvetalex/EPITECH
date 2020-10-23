/*
** EPITECH PROJECT, 2020
** SuperMutant
** File description:
** SuperMutant
*/

#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int16_t dmg)
{
    if (dmg < 0)
        return;
    this->_hp -= (dmg - 3);
}