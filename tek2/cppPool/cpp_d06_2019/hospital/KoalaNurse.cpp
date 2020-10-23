/*
** EPITECH PROJECT, 2020
** KoalaNurse
** File description:
** KoalaNurse
*/

#include <iostream>
#include <fstream>
#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(uint16_t id) : _id(id), _isWorking(false)
{
    return;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->_id << ": Finally some rest!" << std::endl;
    return;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    if (drug.empty() || !patient)
        return;
    patient->takeDrug(drug);
    return;
}

std::string KoalaNurse::readReport(std::string report)
{
    std::ifstream file(report);
    std::string drug;
    std::string name;

    if (report.empty() || !file)
        return(std::string(""));
    file >> drug;
    if (report.find(std::string(".report")) == std::string::npos || drug.empty())
        return (std::string(""));
    name = report.substr(0, report.find(std::string(".report")));
    if (drug == "Eucalyptus")
        drug += " leaf";
    std::cout << "Nurse " << this->_id << ": Kreog! Mr." << name << " needs a " << drug << "!" << std::endl;
    return(drug);
}

void KoalaNurse::timeCheck(void)
{
    this->_isWorking = !this->_isWorking;
    if (this->_isWorking)
        std::cout << "Nurse " << this->_id << ": Time to get to work!" << std::endl;
    else
        std::cout << "Nurse " << this->_id << ": Time to go home to my eucalyptus forest!" << std::endl;
    return;
}

uint16_t KoalaNurse::getID(void)
{
    return (this->_id);
}