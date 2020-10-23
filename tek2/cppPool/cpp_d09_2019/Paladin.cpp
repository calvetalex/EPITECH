/*
** EPITECH PROJECT, 2020
** Paladin
** File description:
** Paladin
*/

#include <iostream>
#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int16_t level, const std::string newWeapon): Character(name, level), Warrior(name, level, newWeapon), Priest(name, level)
{
    this->_race = "Human";
    this->_strength = 9;
    this->_stamina = 10;
    this->_intelligence = 10;
    this->_spirit = 10;
    this->_agility = 2;
    std::cout << "the light falls on " << name << std::endl;
}

Paladin::~Paladin()
{
}

int16_t Paladin::Intercept(void)
{
    return Warrior::RangeAttack();
}