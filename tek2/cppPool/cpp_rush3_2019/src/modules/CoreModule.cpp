/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CoreModule
*/

//! \date 01 February 2020
//! \version
//! \author Kevin Bals

//! \file CoreModule.cpp
//! \brief Set and get CoreModule
#include "./modules/CoreModule.hpp"
#include <iostream>

CoreModule::CoreModule()
{
}

CoreModule::~CoreModule()
{
}

//! \fn void extractInfos()
//! \brief Take all informations to send to setter

//! \param[in] void
//! \param[out] void
void CoreModule::extractInfos(void)
{
    struct sysinfo s_info;
    std::string totalram;
    std::string totalswap;
    std::string freeram;
    std::string freeswap;
    std::string useram;
    std::string useswap;

    sysinfo (&s_info);
    totalram = std::to_string(s_info.totalram / (1024 * 1024));
    totalswap = std::to_string(s_info.totalswap / (1024 * 1024));
    freeram = std::to_string(s_info.freeram / (1024 * 1024));
    freeswap = std::to_string(s_info.freeswap / (1024 * 1024));
    useram = std::to_string((s_info.totalram / (1024 * 1024)) - (s_info.freeram / (1024 *1024)));
    useswap = std::to_string((s_info.totalswap / (1024 * 1024)) - (s_info.freeswap / (1024 *1024)));
    setProcess(std::to_string(s_info.procs));
    setTotalRam(totalram);
    setTotalSwap(totalswap);
    setFreeRam(freeram);
    setUseRam(useram);
    setFreeSwap(freeswap);
    setUseSwap(useswap);
}

//! \fn void setProcess(const std::string)
//! \brief Set Process information

//! \param[in] const std::string
//! \param[out] void
void CoreModule::setProcess(const std::string process)
{
    _process = process;
}

//! \fn std::string getProcess()
//! \brief Get Process information

//! \param[in] void
//! \param[out] std::string
std::string CoreModule::getProcess(void) const
{
    return _process;
}

//! \fn void setTotalRam(const std::string)
//! \brief Set TotalRam information

//! \param[in] const std::string
//! \param[out] void
void CoreModule::setTotalRam(const std::string totalram)
{
    _totalram = totalram;
}


//! \fn std::string getTotalRam()
//! \brief Get TotalRam information

//! \param[in] void
//! \param[out] std::string
std::string CoreModule::getTotalRam(void) const
{
    return _totalram;
}

//! \fn void setFreeRam(const std::string)
//! \brief Set Freeram information

//! \param[in] const std::string
//! \param[out] void
void CoreModule::setFreeRam(const std::string Freeram)
{
    _freeram = Freeram;
}

//! \fn std::string getFreeRam()
//! \brief Get Freeram information

//! \param[in] void
//! \param[out] std::string
std::string CoreModule::getFreeRam(void) const
{
    return _freeram;
}

//! \fn void setUseRam(const std::string)
//! \brief Set Useram information

//! \param[in] const std::string
//! \param[out] void
void CoreModule::setUseRam(const std::string Useram)
{
    _useram = Useram;
}

//! \fn std::string getUseRam()
//! \brief Get Useram information

//! \param[in] void
//! \param[out] std::string
std::string CoreModule::getUseRam(void) const
{
    return _useram;
}


// Swap


//! \fn void setTotalSwap(const std::string)
//! \brief Set TotalSwap information

//! \param[in] const std::string
//! \param[out] void
void CoreModule::setTotalSwap(const std::string totalswap)
{
    _totalswap = totalswap;
}

//! \fn std::string getTotalSwap()
//! \brief Get TotalSwap information

//! \param[in] void
//! \param[out] std::string
std::string CoreModule::getTotalSwap(void) const
{
    return _totalswap;
}

//! \fn void setFreeSwap(const std::string)
//! \brief Set FreeSwap information

//! \param[in] const std::string
//! \param[out] void
void CoreModule::setFreeSwap(const std::string Freeswap)
{
    _freeswap = Freeswap;
}

//! \fn std::string getFreeSwap()
//! \brief Get FreeSwap information

//! \param[in] void
//! \param[out] std::string
std::string CoreModule::getFreeSwap(void) const
{
    return _freeswap;
}

//! \fn void setUseSwap(const std::string)
//! \brief Set UseSwap information

//! \param[in] const std::string
//! \param[out] void
void CoreModule::setUseSwap(const std::string Useswap)
{
    _useswap = Useswap;
}

//! \fn std::string getUseSwap()
//! \brief Get UseSwap information

//! \param[in] void
//! \param[out] std::string
std::string CoreModule::getUseSwap(void) const
{
    return _useswap;
}
