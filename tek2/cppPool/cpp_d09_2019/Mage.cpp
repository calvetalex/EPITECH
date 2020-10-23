/*
** EPITECH PROJECT, 2020
** Mage
** File description:
** Mage
*/

#include <iostream>
#include "Mage.hpp"

Mage::Mage(const std::string &name, int16_t level): Character(name, level)
{
    this->_race = "Gnome";
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    this->Range = Character::RANGE;
    std::cout << name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int16_t Mage::CloseAttack(void)
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    this->_power -= 10;
    this->Range = Character::RANGE;
    std::cout << this->_name << " blinks" << std::endl;
    return 0;
}
int16_t Mage::RangeAttack(void)
{
    if (this->_power < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    this->_power -= 25;
    std::cout << this->_name << " launches a fire ball" << std::endl;
    return (20 + this->_spirit);
}

void Mage::RestorePower(void)
{
    this->_power += 50 + this->_intelligence;
    if (this->_power > 100)
        this->_power = 100;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}