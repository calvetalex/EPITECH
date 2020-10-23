/*
** EPITECH PROJECT, 2020
** Warrior
** File description:
** Warrior
*/

#include <iostream>
#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int16_t lvl, const std::string Weapon): Character(name, lvl)
{
    this->_race = "Dwarf";
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
    this->weaponName = Weapon;
    this->Range = Character::CLOSE;
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int16_t Warrior::CloseAttack(void)
{
    if (this->_power > 30) {
        this->_power -= 30;
        std::cout << this->_name << " strikes with his " << this->weaponName << std::endl;
        return (20 + this->_strength);
    }
    std::cout << this->_name << " out of power" << std::endl;
    return 0;
}

int16_t Warrior::RangeAttack(void)
{
    if (this->_power > 10) {
        this->_power -= 10;
        std::cout << this->_name << " intercepts" << std::endl;
        this->Range = Character::CLOSE;
        return (0);
    }
    std::cout << this->_name << " out of power" << std::endl;
    return 0;
}