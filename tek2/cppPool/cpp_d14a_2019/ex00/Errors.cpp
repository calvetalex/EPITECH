/*
** EPITECH PROJECT, 2020
** Errors
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(const std::string &message, const std::string &component)
{
    this->_msg = message;
    this->_cmp = component;
}

NasaError::~NasaError()
{
}

const std::string &NasaError::getComponent(void) const
{
    return this->_cmp;
}

const char *NasaError::what(void) const throw()
{
    return this->_msg.c_str();
}

LifeCriticalError::LifeCriticalError(const std::string &message, const std::string &component): NasaError(message, component)
{
}

MissionCriticalError::MissionCriticalError(const std::string &message, const std::string &component): NasaError(message, component)
{
}

CommunicationError::CommunicationError(const std::string &message, const std::string &component): NasaError(message, component)
{
}

const std::string &CommunicationError::getComponent(void) const
{
    return "CommunicationDevice";
}

UserError::UserError(const std::string &message, const std::string &component): NasaError(message, component)
{
}