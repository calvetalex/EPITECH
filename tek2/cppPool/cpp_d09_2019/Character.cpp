/*
** EPITECH PROJECT, 2020
** Family matter
** File description:
** Character
*/

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string &name, int16_t lvl): _level(1), _pv(100), _power(100),
    _race("Human"), _strength(5), _stamina(5), _intelligence(5), _spirit(5), _agility(5)
{
    this->_name = name;
    this->_level = lvl;
    this->Range = Character::CLOSE;
    std::cout << name << " Created" << std::endl;
}

Character::~Character()
{
}

int16_t Character::CloseAttack(void)
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    this->_power -= 10;
    std::cout << this->_name << " strikes with a wooden stick" << std::endl;
    return (10 + this->_strength);
}

int16_t Character::RangeAttack(void)
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
    this->_power -= 10;
    std::cout << this->_name << " tosses a stone" << std::endl;
    return (5 + this->_strength);
}

void Character::Heal(void)
{
    this->_pv += 50;
    if (this->_pv > 100)
        this->_pv = 100;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Character::RestorePower(void)
{
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int16_t damages)
{
    if (this->_pv > 0 && this->_pv - damages > 0) {
        std::cout << this->_name << " takes " << damages << " damage" << std::endl;
        this->_pv -= damages;
    } else {
        this->_pv = 0;
        std::cout << this->_name << " out of combat" << std::endl;
    }
}