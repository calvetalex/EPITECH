/*
** EPITECH PROJECT, 2020
** DroidMemory
** File description:
** DroidMemory
*/

#include <iostream>
#include "DroidMemory.hpp"

DroidMemory::DroidMemory(): Fingerprint(random()), Exp(0)
{
}

DroidMemory::~DroidMemory()
{
}

void DroidMemory::setFingerprint(size_t newFingerprint)
{
    this->Fingerprint = newFingerprint;
}

void DroidMemory::setExp(size_t newExp)
{
    this->Exp = newExp;
}

bool DroidMemory::operator<<(DroidMemory& memory)
{
    this->Exp += memory.getExp();
    return this->Fingerprint ^ memory.getFingerprint();
}

bool DroidMemory::operator>>(DroidMemory& memory)
{
    memory.setExp(memory.getExp() + this->Exp);
    return memory.getFingerprint() ^ this->Fingerprint;
}

bool DroidMemory::operator+=(DroidMemory& memory)
{
    return *this << memory;
}

bool DroidMemory::operator+=(size_t& exp)
{
    this->Exp += exp;
    return exp ^ this->Fingerprint;
}

DroidMemory DroidMemory::operator+(DroidMemory& memory)
{
    DroidMemory newOne;

    newOne.setExp(newOne.Exp +memory.Exp);
    newOne.setFingerprint(newOne.Fingerprint ^ memory.Fingerprint);
    return newOne;
}

std::ostream& operator<<(std::ostream& stream, DroidMemory &memoryToPrint)
{
    stream << "DroidMemory '" << memoryToPrint.getFingerprint() << "', " << memoryToPrint.getExp() ;
    return stream;
}