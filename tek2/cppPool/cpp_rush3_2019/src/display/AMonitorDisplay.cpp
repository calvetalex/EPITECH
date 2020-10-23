/*
** EPITECH PROJECT, 2020
** AMonitorDisplay
** File description:
** AMonitorDisplay
*/

#include "display/AMonitorDisplay.hpp"

AMonitorDisplay::AMonitorDisplay(const std::list<std::string> &moduleList)
{
     for(auto it = moduleList.begin(); it != moduleList.end(); ++it) {
        if (it->compare("UserModule") == 0)
            this->_modules.insert(std::pair<std::string, IMonitorModule*>("UserModule", new (UserModule)));
        else if (it->compare("CoreModule") == 0)
            this->_modules.insert(std::pair<std::string, IMonitorModule*>("OsModule", new (OsModule)));
        else if (it->compare("TimeModule") == 0)
            this->_modules.insert(std::pair<std::string, IMonitorModule*>("TimeModule", new (TimeModule)));
        else if (it->compare("OsModule") == 0)
            this->_modules.insert(std::pair<std::string, IMonitorModule*>("CoreModule", new (CoreModule)));
    }
}

AMonitorDisplay::AMonitorDisplay(const AMonitorDisplay &initial)
{
    this->_modules = initial.getModules();
    this->_screenInfo = initial.getScreenInfo();
}

AMonitorDisplay::~AMonitorDisplay()
{
    if (!this->_screenInfo.empty())
        this->_screenInfo.clear();
    for (auto it = _modules.begin(); it != _modules.end(); it++)
        _modules.erase(it);
    _modules.clear();
}

std::map<std::string, uint16_t> AMonitorDisplay::getScreenInfo(void) const
{
    return this->_screenInfo;
}

void AMonitorDisplay::setScreenInfo(uint16_t width, uint16_t height)
{
    this->_screenInfo.insert(std::pair<std::string, uint16_t>("height", height));
    this->_screenInfo.insert(std::pair<std::string, uint16_t>("width", width));
}

void AMonitorDisplay::resetScreen(void)
{
    if (!this->_screenInfo.empty())
        this->_screenInfo.clear();
    this->_screenInfo.insert(std::pair<std::string, uint16_t>("height", 1920));
    this->_screenInfo.insert(std::pair<std::string, uint16_t>("width", 1080));
}

void AMonitorDisplay::updateModules(void)
{
    for (std::map<std::string, IMonitorModule*>::iterator it = _modules.begin(); it != _modules.end(); it++) {
        it->second->extractInfos();
    }
}

std::map<std::string, IMonitorModule*> AMonitorDisplay::getModules(void) const
{
    return this->_modules;
}
