/*
** EPITECH PROJECT, 2020
** Priest
** File description:
** Priest
*/

#include <iostream>
#include "Priest.hpp"

Priest::Priest(const std::string &name, int16_t level): Character(name, level), Mage(name, level)
{
    this->_race = "Orc";
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    this->Range = Character::RANGE;
    std::cout << name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

int16_t Priest::CloseAttack(void)
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    this->_power -= 10;
    this->Range = Character::RANGE;
    std::cout << this->_name << " uses a spirit explosion" << std::endl;
    return (10 + this->_spirit);
}

void Priest::Heal(void)
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return;
    }
    this->_power -= 10;
    this->_pv += 70;
    std::cout << this->_name << " casts a little heal spell" << std::endl;
    return;
}