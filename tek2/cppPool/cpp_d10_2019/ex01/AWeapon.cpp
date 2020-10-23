/*
** EPITECH PROJECT, 2020
** AWeapon
** File description:
** AWeapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int16_t apcost, int16_t dmg)
{
    this->_name = name;
    this->_apcost = apcost;
    this->_damage = dmg;
}

AWeapon::~AWeapon()
{
}