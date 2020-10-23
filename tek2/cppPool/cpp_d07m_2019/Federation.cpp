/*
** EPITECH PROJECT, 2020
** Federation
** File description:
** Federation
*/

#include <iostream>
#include "Federation.hpp"

// FEDERATION SHIP

Federation::Starfleet::Ship::Ship(int16_t length, int16_t width, std::string name, short maxWarp, int16_t torpedo): _shipCore(nullptr), _home(EARTH)
{
    this->_length = length;
    this->_width = width;
    this->_maxWarp = maxWarp;
    this->_name = name;
    this->_location = this->_home;
    this->_photonTorpedo = torpedo;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (torpedo != 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
    return;
}

Federation::Starfleet::Ship::Ship():   _length(289), _width(132), _name("Entreprise"), _maxWarp(6), _shipCore(nullptr), _captain(nullptr), _home(EARTH), _location(_home), _shield(100), _photonTorpedo(0)
{
    std::cout << "The ship USS Entreprise has been finished." << std::endl;
    std::cout << "It is 289 m in length and 132 m in width." << std::endl;
    std::cout << "It can go to Warp 6!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
    return;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *newCore)
{
    this->_shipCore = newCore;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
    return;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    std::string stable = this->_shipCore->checkReactor()->isStable() == true ? "stable" : "unstable";
    std::cout << "USS " << this->_name << ": The core is " << stable << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *newCaptain)
{
    this->_captain = newCaptain;
    std::cout << this->_captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int16_t warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_shipCore->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != this->_location && this->_shipCore->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int16_t warp)
{
    if (warp <= this->_maxWarp && this->_location != this->_home && this->_shipCore->checkReactor()->isStable() == true) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(void)
{
    if (this->_location != this->_home && this->_shipCore->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

int16_t Federation::Starfleet::Ship::getShield(void)
{
    return (this->_shield);
}

void Federation::Starfleet::Ship::setShield(int16_t newShield)
{
    this->_shield = newShield;
}

int16_t Federation::Starfleet::Ship::getTorpedo(void)
{
    return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int16_t torpedo)
{
    this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (this->_photonTorpedo < 1)
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
    else {
        this->_photonTorpedo -= 1;
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield((target->getShield() - 50));
        if (this->_photonTorpedo == 0)
            std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
    }
    return;
}

void Federation::Starfleet::Ship::fire(int16_t torpedo, Borg::Ship *target)
{
    if (torpedo > this->_photonTorpedo)
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
    else {
        this->_photonTorpedo -= torpedo;
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield((target->getShield() - (50 * torpedo)));
        if (this->_photonTorpedo == 0)
            std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
    }
}

// FEDERATION CAPTAIN

Federation::Starfleet::Captain::Captain(std::string name): _name(name), _age(0)
{
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return this->_name;
}

int16_t Federation::Starfleet::Captain::getAge()
{
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int16_t newAge)
{
    this->_age = newAge;
}

// FEDERATION ENSIGN

Federation::Starfleet::Ensign::Ensign(std::string name): _name(name)
{
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

// INDEPENDANT SHIP

Federation::Ship::Ship(int16_t length, int16_t width, std::string name): _maxWarp(1), _home(VULCAN)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_location = _home;
    std::cout << "The independent ship " << name << " just finished its constrution." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    return;
}

Federation::Ship::~Ship()
{
    return;
}

void Federation::Ship::setupCore(WarpSystem::Core *newCore)
{
    this->_shipCore = newCore;
    std::cout << this->_name << ": The core is set." << std::endl;
    return;
}

void Federation::Ship::checkCore(void)
{
    std::string stable = this->_shipCore->checkReactor()->isStable() == true ? "stable" : "unstable";
    std::cout << this->_name << ": The core is " << stable << " at the time." << std::endl;
}

bool Federation::Ship::move(int16_t warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_shipCore->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != this->_location && this->_shipCore->checkReactor()->isStable() == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int16_t warp)
{
    if (warp <= this->_maxWarp && this->_location != this->_home && this->_shipCore->checkReactor()->isStable() == true) {
        this->_location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(void)
{
    if (this->_location != this->_home && this->_shipCore->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

int16_t Federation::Ship::getShield(void)
{
    return (this->_shield);
}

void Federation::Ship::setShield(int16_t newShield)
{
    this->_shield = newShield;
}

int16_t Federation::Ship::getTorpedo(void)
{
    return (this->_photonTorpedo);
}

void Federation::Ship::setTorpedo(int16_t torpedo)
{
    this->_photonTorpedo = torpedo;
}

WarpSystem::Core *Federation::Ship::getCore(void)
{
    return this->_shipCore;
}