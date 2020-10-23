/*
** EPITECH PROJECT, 2020
** SickKoala
** File description:
** functions of Koala
*/

#include <iostream>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string newName) : _name(newName)
{
    return;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->_name << ": Kreooogg!! I'm cuuuured!" << std::endl;
    return;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << this->_name << ": Gooeeeeerrk!!" << std::endl;
    return;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars") {
        std::cout << "Mr." << this->_name << ": Mars, and it kreogs!" << std::endl;
        return (true);
    }
    if (drug == "Buronzand") {
        std::cout << "Mr." << this->_name << ": And you'll sleep right away!" << std::endl;
        return (true);
    }
    std::cout << "Mr." << this->_name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string str)
{
    size_t to_replace = 0;

    while ((to_replace = str.find("Kreog!", to_replace)) != std::string::npos)
        str.replace(to_replace, 6, "1337!");
    std::cout << "Mr." << this->_name << ": " << str << std::endl;
}

std::string SickKoala::getName(void)
{
    return (this->_name);
}