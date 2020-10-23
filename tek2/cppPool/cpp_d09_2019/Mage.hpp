/*
** EPITECH PROJECT, 2020
** Mage
** File description:
** Mage
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage: virtual public Character
{
    public:
        Mage(const std::string &, int16_t);
        ~Mage();
        int16_t CloseAttack();
        int16_t RangeAttack();
        void RestorePower();
};

#endif /* !WARRIOR_HPP_ */