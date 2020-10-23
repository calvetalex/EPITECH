/*
** EPITECH PROJECT, 2020
** KoalaDoctor
** File description:
** KoalaDoctor
*/

#include <string>
#include <iostream>
#include <fstream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : _name(name)
{
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
    return;
}

KoalaDoctor::~KoalaDoctor()
{
    return;
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string patientName;
    std::string reportTitle;
    std::string drugs[] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
    std::ofstream report;

    if (!patient)
        return;
    patientName = patient->getName();
    if (patientName.empty())
        return;
    reportTitle = patientName + ".report";
    std::cout << "Dr." << this->_name << ": So what's goerking you Mr." << patientName << "?" << std::endl;
    patient->poke();
    report.open(reportTitle);
    report << drugs[random() % 5] << std::endl;
    report.close();
}

void KoalaDoctor::timeCheck(void)
{
    this->_isWorking = !this->_isWorking;
    if (this->_isWorking)
        std::cout << "Dr." << this->_name << ": Time to get to work!" << std::endl;
    else
        std::cout << "Dr." << this->_name << ": Time to go home to my eucalyptus forest!" << std::endl;
}

std::string KoalaDoctor::getName(void)
{
    return (this->_name);
}