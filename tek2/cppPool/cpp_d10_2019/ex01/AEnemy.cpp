/*
** EPITECH PROJECT, 2020
** AEnemy
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int16_t hp, const std::string &type)
{
    this->_hp = hp;
    this->_type = type;
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int16_t dmg)
{
    if (dmg < 0)
        return;
    this->_hp -= dmg;
}