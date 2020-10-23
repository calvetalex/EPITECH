/*
** EPITECH PROJECT, 2020
** KoalaBot
** File description:
** KoalaBot
*/

#include <iostream>
#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string name): _name(name)
{
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms &newArms)
{
    this->_arms = newArms;
}

void KoalaBot::setParts(Legs &newLegs)
{
    this->_legs = newLegs;
}

void KoalaBot::setParts(Head &newHead)
{
    this->_head = newHead;
}

void KoalaBot::swapParts(Arms& newArms)
{
    Arms tmp;
    tmp = this->_arms;
    this->_arms = newArms;
    newArms = tmp;
}

void KoalaBot::swapParts(Legs& newLegs)
{
    Legs tmp;
    tmp = this->_legs;
    this->_legs = newLegs;
    newLegs = tmp;
}

void KoalaBot::swapParts(Head& newHead)
{
    Head tmp;
    tmp = this->_head;
    this->_head = newHead;
    newHead = tmp;
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << this->_name << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status(void) const
{
    if (this->_arms.isFunctionnal() && this->_legs.isFunctionnal() && this->_head.isFunctionnal())
        return true;
    return false;
}