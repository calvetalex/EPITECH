/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** AMonitorModule
*/

#include <iostream>
#include <fstream>
#include "./modules/AMonitorModule.hpp"

AMonitorModule::AMonitorModule()
{
}

AMonitorModule::~AMonitorModule()
{
}

std::string AMonitorModule::getInfosFromShell(const std::string &command)
{
    std::string result("");

    std::system(command.c_str());
    getline(std::ifstream(TMP_FILE_PATH), result);
    return result;
}
