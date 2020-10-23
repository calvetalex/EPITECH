/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OsModule
*/

//! \date 01 February 2020
//! \version
//! \author Noé Heuillet

//! \file OsModule.cpp
//! \brief Get and set os module
//  
#include <sys/utsname.h>
#include <iostream>
#include <fstream>
#include "./modules/AMonitorModule.hpp"
#include "./modules/OsModule.hpp"

OsModule::OsModule() : AMonitorModule()
{
    _kernelVersion = "";
    _os = "";
    _cpu = "";
    _gpu = "";
}

OsModule::OsModule(const OsModule &initial) : AMonitorModule()
{
    _kernelVersion = initial._kernelVersion;
    _os = initial._os;
    _gpu = initial._gpu;
    _cpu = initial._cpu;
}

OsModule::~OsModule()
{
}

const OsModule &OsModule::operator=(const OsModule &rhs)
{
    this->_kernelVersion = rhs._kernelVersion;
    this->_os = rhs._os;
    this->_cpu = rhs._cpu;
    this->_gpu = rhs._gpu;
    return *this;
}

//! \fn void setOs(const std::string)
//! \brief Set Os information

//! \param[in] const std::string
//! \param[out] void
void OsModule::setOs(const std::string &os)
{
    _os = os;
}

//! \fn void setCpu(const std::string)
//! \brief Set Cpu information

//! \param[in] const std::string
//! \param[out] void
void OsModule::setCpu(const std::string &cpu)
{
    _cpu = cpu;
}

//! \fn void setGpu(const std::string)
//! \brief Set Gpu information

//! \param[in] const std::string
//! \param[out] void
void OsModule::setGpu(const std::string &gpu)
{
    _gpu = gpu;
}

//! \fn void setKernel(const std::string)
//! \brief Set Kernel information

//! \param[in] const std::string
//! \param[out] void
void OsModule::setKernel(const std::string &kernel)
{
    _kernelVersion = kernel;
}

//! \fn std::string getKernel()
//! \brief Get Kernel information

//! \param[in] void
//! \param[out] std::string
const std::string &OsModule::getKernel(void)
{
    return _kernelVersion;
}

//! \fn std::string getOs()
//! \brief Get Os information

//! \param[in] void
//! \param[out] std::string
const std::string &OsModule::getOs(void)
{
    return _os;
}

//! \fn std::string getCpu()
//! \brief Get Cpu information

//! \param[in] void
//! \param[out] std::string
const std::string &OsModule::getCpu(void)
{
    return _cpu;
}

//! \fn std::string getGpu()
//! \brief Get Gpu information

//! \param[in] void
//! \param[out] std::string
const std::string &OsModule::getGpu(void)
{
    return _gpu;
}

//! \fn void extractInfos()
//! \brief Take all informations to send to setter

//! \param[in] void
//! \param[out] void
void OsModule::extractInfos(void)
{
    struct utsname infos;
    std::string cpuInfos;
    std::string gpuInfos;

    uname(&infos);
    setKernel(std::string(infos.release));
    setOs(std::string(infos.sysname));
    cpuInfos = getInfosFromShell(CPUCOMMAND);
    setCpu(cpuInfos);
    gpuInfos = getInfosFromShell(GPUCOMMAND);
    setGpu(gpuInfos.c_str());
}
