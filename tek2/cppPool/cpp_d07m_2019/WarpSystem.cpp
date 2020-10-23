/*
** EPITECH PROJECT, 2020
** WarpSystem
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(): _stability(true)
{
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable(void)
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool newStability)
{
    this->_stability = newStability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *newReactor): _coreReactor(newReactor)
{
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor(void)
{
    return this->_coreReactor;
}