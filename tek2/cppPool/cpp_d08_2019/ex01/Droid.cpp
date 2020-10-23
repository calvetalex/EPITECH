/*
** EPITECH PROJECT, 2020
** Droid
** File description:
** Droid
*/

#include <iostream>
#include "Droid.hpp"

// Ctor Dtr

Droid::Droid(std::string serial): Energy(50), Attack(25), Toughness(15), Status(new std::string("Standing by"))
{
    this->Id = serial;
    this->BattleData = new DroidMemory();
    std::cout << "Droid '"<< serial << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid): Attack(droid.Attack), Toughness(droid.Toughness)
{
    this->Id = droid.Id;
    this->Energy = droid.Energy;
    this->Status = droid.Status;
    std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

// Set && Get
void Droid::setId(std::string newId)
{
    this->Id = newId;
}

void Droid::setEnergy(size_t newEnergy)
{
    this->Energy = newEnergy;
}

void Droid::setStatus(std::string *newStatus)
{
    this->Status = newStatus;
}

// Detect cout
std::ostream& operator<<(std::ostream& stream, Droid &droidToPrint)
{
    stream << "Droid '" << droidToPrint.getId() << "', " << *droidToPrint.getStatus() << ", " << droidToPrint.getEnergy();
    return stream;
}

// overload operators
Droid Droid::operator=(Droid &droid)
{
    if (&droid != this) {
        this->Id = droid.getId();
        this->Energy = droid.getEnergy();
        if (this->Status)
            delete(this->Status);
        this->Status = new std::string(*droid.getStatus());
    }
    return *this;
}

Droid &Droid::operator<<(size_t &battery)
{
    this->Energy += battery;

    if (this->Energy > 100) {
        battery = this->Energy - 100;
        this->Energy = 100;
    } else {
        battery = 0;
    }
    return *this;
}

bool Droid::operator!=(Droid &droid)
{
    if (droid.getId() == this->Id && droid.getEnergy() == this->Energy && this->Status->compare(*droid.getStatus()) == 0)
        return false;
    return true;
}

bool Droid::operator==(Droid &droid)
{
    if (this->Status->compare(*droid.getStatus()) == 0)
        return true;
    return false;
}