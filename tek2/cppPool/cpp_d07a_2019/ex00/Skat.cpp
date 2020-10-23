/*
** EPITECH PROJECT, 2020
** Skat
** File description:
** Skat
*/

#include <iostream>
#include "Skat.hpp"

Skat::Skat(const std::string &name, int16_t newStimPacks)
{
    this->_name = name;
    this->_stimPaks = newStimPacks;
}

Skat::~Skat()
{
}

int16_t &Skat::stimPaks(void)
{
    return (this->_stimPaks);
}

const std::string &Skat::name()
{
    return(this->_name);
}

void Skat::shareStimPaks(int16_t number, int16_t &stock)
{
    if (number > this->_stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    _stimPaks -= number;
    stock += number;
    std::cout << "Keep the change." << std::endl;
    return;
}

void Skat::addStimPaks(uint16_t number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    _stimPaks += number;
    return;
}

void Skat::useStimPaks(void)
{
    if (this->_stimPaks > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        this->_stimPaks--;
    } else
        std::cout << "Mediiiiiic" << std::endl;
    return;
}

void Skat::status(void)
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}