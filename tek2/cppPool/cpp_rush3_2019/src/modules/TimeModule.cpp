/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TimeModule
*/

//! \date 01 February 2020
//! \version
//! \author Kevin Bals

//! \file TimeModule.cpp
//! \brief Set and get TimeModule
#include "./modules/TimeModule.hpp"

TimeModule::TimeModule()
{
    _uptime = "";
    _date = "";
}

TimeModule::TimeModule(const TimeModule &initial)
{
    _uptime = initial._uptime;
    _date = initial._date;
}

TimeModule::~TimeModule()
{
}

const TimeModule &TimeModule::operator=(const TimeModule &rhs)
{
    _uptime = rhs._uptime;
    _date = rhs._date;
    return *this;
}

//! \fn void extractInfos()
//! \brief Take all informations to send to setter

//! \param[in] void
//! \param[out] void
void TimeModule::extractInfos()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    std::string uptime;
    int days = (t.tv_sec/ 86400);
    int hours = (t.tv_sec/ 3600) - (days * 24);
    int mins = (t.tv_sec/ 60) - (days * 1440) - (hours * 60);

    uptime = std::to_string(days) + " Days " + std::to_string(hours) + " Hours " + std::to_string(mins) + " Mins";
    setUpTime(uptime);
    if (dt)
        setDate(dt);
    else
        setDate(nullptr);
}

//! \fn std::string getDate()
//! \brief Get date information

//! \param[in] void
//! \param[out] std::string
std::string TimeModule::getDate(void) const
{
    return _date;
}

//! \fn void setDate(const std::string)
//! \brief Set date information

//! \param[in] const std::string
//! \param[out] void
void TimeModule::setDate(const std::string dt)
{
    _date = dt;
}

//! \fn std::string getUpTime()
//! \brief Get UpTime informations

//! \param[in] void
//! \param[out] std::string
std::string TimeModule::getUpTime(void) const
{
    return _uptime;
}

//! \fn void setUpTime(const std::string)
//! \brief Set UpTime information

//! \param[in] const std::string
//! \param[out] void
void TimeModule::setUpTime(const std::string uptime)
{
    _uptime = uptime;
}