/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UserModule
*/

//! \date 01 February 2020
//! \version
//! \author Kevin Bals

//! \file CoreModule.cpp
//! \brief Set and get CoreModule
#include <sys/utsname.h>
#include "./modules/UserModule.hpp"

UserModule::UserModule()
{
    _hostname = "";
    _username = "";
}

UserModule::~UserModule()
{
}

//! \fn void setHostName(const std::string)
//! \brief Set HostName information

//! \param[in] const std::string
//! \param[out] void
void UserModule::setHostName(const std::string &hostname)
{
    _hostname = hostname;
}

//! \fn void setUserName(const std::string)
//! \brief Set UserName information

//! \param[in] const std::string
//! \param[out] void
void UserModule::setUserName(const std::string &username)
{
    _username = username;
}

//! \fn std::string geUserName()
//! \brief Get UserName informations

//! \param[in] void
//! \param[out] std::string
const std::string &UserModule::getUserName(void)
{
    return _username;
}

//! \fn std::string getHostName()
//! \brief Get HostName informations

//! \param[in] void
//! \param[out] std::string
const std::string &UserModule::getHostName(void)
{
    return _hostname;
}

//! \fn void extractInfos()
//! \brief Take all informations to send to setter

//! \param[in] void
//! \param[out] void
void UserModule::extractInfos(void)
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    struct utsname infos;

    if (pw)
        setUserName(std::string(pw->pw_name));
    else
        setUserName(std::string(""));
    uname(&infos);
    setHostName(std::string(infos.nodename));
}
