/*
** EPITECH PROJECT, 2020
** Character
** File description:
** Character
*/

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string &name): _ap(40)
{
    this->_name = name;
    this->_gun = nullptr;
}

Character::~Character()
{
}

void Character::recoverAP(void)
{
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

// void Character::attack(AEnemy *enemy)
// {
//     if (this->_gun->getAPCost() > this->_ap)
//         return;
//     std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_gun->getName() << std::endl;
//     this->_gun->attack();
//     enemy->takeDamage(this->_gun->getDamage());
//     if (enemy->getHP() <= 0)
//         enemy->~AEnemy();
// }

void Character::attack(AEnemy *enemy)
{
    if (_gun == nullptr)
        return;
    else if (_ap < _gun->getAPCost())
        return;
    if (enemy != nullptr) {
        _ap -= _gun->getAPCost();
        std::cout << _name << " attacks " << enemy->getType() << " with a " << _gun->getName() << std::endl;
        _gun->attack();
        enemy->takeDamage(_gun->getDamage());
        if (enemy->getHP() <= 0)
            delete (enemy);
    }
}

void Character::equip(AWeapon *weapon)
{
    this->_gun = weapon;
}

std::ostream &operator<<(std::ostream &stream, Character &player)
{
    if (player.getWeapon())
        stream << player.getName() << " has " << player.getAp() << " AP and wields a " << player.getWeapon()->getName() << std::endl;
    else
        stream << player.getName() << " has " << player.getAp() << " AP and is unarmed" << std::endl;
    return stream;
}