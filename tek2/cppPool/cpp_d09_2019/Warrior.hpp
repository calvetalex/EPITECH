/*
** EPITECH PROJECT, 2020
** Warrior
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior: virtual public Character
{
    public:
        Warrior(const std::string &, int16_t, const std::string = "hammer");
        ~Warrior();
        int16_t CloseAttack();
        int16_t RangeAttack();
    protected:
        std::string weaponName;
};

#endif /* !WARRIOR_HPP_ */
