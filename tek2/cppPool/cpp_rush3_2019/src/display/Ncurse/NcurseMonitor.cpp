/*
** EPITECH PROJECT, 2020
** NcurseMonitor
** File description:
** NcurseMonitor
*/

//! \date 01 February 2020
//! \version
//! \author Alexandre Calvet

//! \file NcurseMonitor.cpp
//! \brief Ncurse Library Monitor
//  Ncurse Library Monitor for all MyGKrellm Project

#include <iostream>

#include <cstring>
#include <ncurses.h>
#include "display/NcurseMonitor.hpp"
#include "modules/CoreModule.hpp"
#include "modules/OsModule.hpp"
#include "modules/TimeModule.hpp"
#include "modules/UserModule.hpp"

//! \fn NcurseMonitor(std::list<std::string> &)
//! \brief Constructor for NcurseMonitor class

//! \param[in] list of activated
NcurseMonitor::NcurseMonitor(std::list<std::string> &moduleList): AMonitorDisplay(moduleList)
{
}

//! \fn NcurseMonitor(std::list<std::string> &)
//! \brief Destructor for NcurseMonitor class
NcurseMonitor::~NcurseMonitor()
{
    if (this->_modules.size() != 0) {
        for (auto it = _modules.begin(); it != _modules.end(); it++)
            _modules.erase(it);
        _modules.clear();
    }
}

//! \fn NcurseMonitor(std::list<std::string> &)
//! \brief Copy Constructor for NcurseMonitor class

//! \param[in] list of activated
NcurseMonitor::NcurseMonitor(const NcurseMonitor&toCopy): AMonitorDisplay(toCopy)
{
}

//! \fn NcurseMonitor(std::list<std::string> &)
//! \brief operator '=' for NcurseMonitor class

//! \param[in] list of activated
NcurseMonitor &NcurseMonitor::operator=(const NcurseMonitor&toAssign)
{
    this->_modules = toAssign.getModules();
    this->_screenInfo = toAssign.getScreenInfo();
    return *this;
}

//! \fn int getMaxY(void)
//! \brief get the height of the box

//! \param[in] void
//! \param[out] int corresponding to the height
//! \return return value will always be a positive number
int16_t NcurseMonitor::getMaxY(void) const
{
    return this->_maxY;
}

//! \fn void setMaxY(int)
//! \brief get the height of the box

//! \param[in] int corresponding to the height
//! \param[out] void
//! \return setter has no return value
void NcurseMonitor::setMaxY(int16_t newMax)
{
    this->_maxY = newMax;
}

//! \fn int getMaxX(void)
//! \brief get the width of the box

//! \param[in] void
//! \param[out] int corresponding to the width
//! \return return value will always be a positive number
int16_t NcurseMonitor::getMaxX(void) const
{
    return this->_maxX;
}

//! \fn void setMaxX(int)
//! \brief get the width of the box

//! \param[in] int corresponding to the width
//! \param[out] void
//! \return setter has no return value
void NcurseMonitor::setMaxX(int16_t newMax)
{
    this->_maxX = newMax;
}

//! \fn void displayUserModule(void)
//! \brief Print the USER Module
// Print the UserName and HostName Informations

//! \param[in] void
//! \param[out] void
//! \return Print Function do nor take neither return anything
void NcurseMonitor::displayUserModule(void)
{
    WINDOW *subWinUser = newwin(_maxY - 4, _maxX / 4, 4, 0);
    const char *hostName= _modules.find("UserModule") != _modules.end() ? static_cast<UserModule*>((this->_modules.find("UserModule"))->second)->getHostName().c_str() : "unknown";
    const char *userName= _modules.find("UserModule") != _modules.end() ? static_cast<UserModule*>((this->_modules.find("UserModule"))->second)->getUserName().c_str() : "unknown";

    box(subWinUser, 0, 0);
    refresh();
    mvwprintw(subWinUser, 1, getmaxx(subWinUser) / 3 - 1, "User Informations");
    wrefresh(subWinUser);
    mvwprintw(subWinUser, 3, getmaxx(subWinUser) / 6, "Host name: ");
    mvwprintw(subWinUser, 3,getmaxx(subWinUser) / 6 * 3, hostName);
    wrefresh(subWinUser);
    mvwprintw(subWinUser, 5, getmaxx(subWinUser) / 6, "User name: ");
    mvwprintw(subWinUser, 5,getmaxx(subWinUser) / 6 * 3, userName);
    wrefresh(subWinUser);
}

//! \fn void displayTimeModule(void)
//! \brief Print the TIME Module
// Print the UpTime and Date Informations

//! \param[in] void
//! \param[out] void
//! \return Print Function do nor take neither return anything
void NcurseMonitor::displayTimeModule(void)
{
    WINDOW *subWinTime = newwin(_maxY - 4, _maxX / 4, 4, _maxX / 4);

    box(subWinTime, 0, 0);
    refresh();
    mvwprintw(subWinTime, 1, getmaxx(subWinTime) / 3 - 1, "Time Informations");
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 3, getmaxx(subWinTime) / 7, "Up Time: ");
    mvwprintw(subWinTime, 3,getmaxx(subWinTime) / 7 * 3, _modules.find("TimeModule") != _modules.end() ? static_cast<TimeModule*>((this->_modules.find("TimeModule"))->second)->getUpTime().c_str() : "unknown");
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 5, getmaxx(subWinTime) / 7, "Date: ");
    mvwprintw(subWinTime, 5,getmaxx(subWinTime) / 7 * 3, _modules.find("TimeModule") != _modules.end() ? static_cast<TimeModule*>((this->_modules.find("TimeModule"))->second)->getDate().c_str() : "unknown");
    wrefresh(subWinTime);
}

//! \fn void displayOsModule(void)
//! \brief Print the OS and KERNEL Module
// Print the Kernel and Operating System Informations

//! \param[in] void
//! \param[out] void
//! \return Print Function do nor take neither return anything
void NcurseMonitor::displayOsModule(void)
{
    WINDOW *subWinTime = newwin(_maxY - 4, _maxX / 4, 4, _maxX / 4 * 2);
    const char *cpu = _modules.find("OsModule") != _modules.end() ? static_cast<OsModule*>((this->_modules.find("OsModule"))->second)->getCpu().c_str() : "unknown";
    const char *gpu = _modules.find("OsModule") != _modules.end() ? static_cast<OsModule*>((this->_modules.find("OsModule"))->second)->getGpu().c_str() : "unknown";
    const char *os = _modules.find("OsModule") != _modules.end() ? static_cast<OsModule*>((this->_modules.find("OsModule"))->second)->getOs().c_str() : "unknown";
    const char *kernel = _modules.find("OsModule") != _modules.end() ? static_cast<OsModule*>((this->_modules.find("OsModule"))->second)->getKernel().c_str() : "unknown";

    box(subWinTime, 0, 0);
    refresh();
    mvwprintw(subWinTime, 1, getmaxx(subWinTime) / 3 - 1, "Neofetch");
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 3, getmaxx(subWinTime) / 8, "Operating system: ");
    mvwprintw(subWinTime, 3,getmaxx(subWinTime) / 8 * 4, os);
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 5, getmaxx(subWinTime) / 8, "Kernel: ");
    mvwprintw(subWinTime, 5,getmaxx(subWinTime) / 8 * 3, kernel);
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 7, getmaxx(subWinTime) / 8, "CPU: ");
    mvwprintw(subWinTime, 7,getmaxx(subWinTime) / 8 * 2, cpu);
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 9, getmaxx(subWinTime) / 8, "GPU: ");
    mvwprintw(subWinTime, 9,getmaxx(subWinTime) / 8 * 2, gpu);
    wrefresh(subWinTime);
}

//! \fn void displayCoreModule(void)
//! \brief Print the Core Module
// Print the Core Informations

//! \param[in] void
//! \param[out] void
//! \return Print Function do nor take neither return anything
void NcurseMonitor::displayCoreModule(void)
{
    WINDOW *subWinTime = newwin(_maxY - 4, _maxX / 4, 4, _maxX / 4 * 3);

    box(subWinTime, 0, 0);
    refresh();
    mvwprintw(subWinTime, 1, getmaxx(subWinTime) / 3 - 1, "Monitor Core");
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 3, getmaxx(subWinTime) / 8, "total Physical memory (Mb): ");
    mvwprintw(subWinTime, 3,getmaxx(subWinTime) / 8 * 6, _modules.find("CoreModule") != _modules.end() ? static_cast<CoreModule*>((this->_modules.find("CoreModule"))->second)->getTotalRam().c_str() : "unknown");
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 5, getmaxx(subWinTime) / 8, "Used Physical memory (Mb): ");
    mvwprintw(subWinTime, 5,getmaxx(subWinTime) / 8 * 6, _modules.find("CoreModule") != _modules.end() ? static_cast<CoreModule*>((this->_modules.find("CoreModule"))->second)->getUseRam().c_str() : "unknown");
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 7, getmaxx(subWinTime) / 8, "Total Swap (Mb): ");
    mvwprintw(subWinTime, 7,getmaxx(subWinTime) / 8 * 6, _modules.find("CoreModule") != _modules.end() ? static_cast<CoreModule*>((this->_modules.find("CoreModule"))->second)->getTotalSwap().c_str() : "unknown");
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 9, getmaxx(subWinTime) / 8, "Used Swap (Mb): ");
    mvwprintw(subWinTime, 9,getmaxx(subWinTime) / 8 * 6, _modules.find("CoreModule") != _modules.end() ? static_cast<CoreModule*>((this->_modules.find("CoreModule"))->second)->getUseSwap().c_str() : "unknown");
    wrefresh(subWinTime);
    mvwprintw(subWinTime, 11, getmaxx(subWinTime) / 8, "Process: ");
    mvwprintw(subWinTime, 11, getmaxx(subWinTime) / 8 * 6, _modules.find("CoreModule") != _modules.end() ? static_cast<CoreModule*>((this->_modules.find("CoreModule"))->second)->getProcess().c_str() : "unknown");
    wrefresh(subWinTime);
}

//! \fn void displayCoreModule(void)
//! \brief Call all Printers
// Call all Informations

//! \param[in] void
//! \param[out] void
//! \return Print Function do nor take neither return anything
void NcurseMonitor::displayModule(void)
{
        this->displayUserModule();
        this->displayTimeModule();
        this->displayOsModule();
        this->displayCoreModule();
}