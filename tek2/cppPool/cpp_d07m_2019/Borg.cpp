/*
** EPITECH PROJECT, 2020
** Borg
** File description:
** Borg
*/

#include <iostream>
#include "Borg.hpp"

Borg::Ship::Ship(int16_t weapon, short repair): _size(300), _maxWarp(9), _home(UNICOMPLEX), _shield(100), _repair(3)
{
    this->_location = _home;
    this->_weaponFrequency = weapon;
    this->_repair = repair;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *newCore)
{
    this->_core = newCore;
}

void Borg::Ship::checkCore(void)
{
    if (this->_core->checkReactor()->isStable() == true)
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int16_t warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int16_t warp)
{
    if (warp <= this->_maxWarp && this->_location != this->_home && this->_core->checkReactor()->isStable() == true) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(void)
{
    if (this->_location != this->_home && this->_core->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

int16_t Borg::Ship::getShield(void)
{
    return (this->_shield);
}

void Borg::Ship::setShield(int16_t newShield)
{
    this->_shield = newShield;
}

int16_t Borg::Ship::getWeaponFrequency(void)
{
    return (this->_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int16_t weapon)
{
    this->_weaponFrequency = weapon;
}

short Borg::Ship::getRepair(void)
{
    return (this->_repair);
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}

void  Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield((target->getShield()) - this->_weaponFrequency);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    if (this->_repair == 0)
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    else {
        this->_repair -= 1;
        this->setShield(100);
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    }
}