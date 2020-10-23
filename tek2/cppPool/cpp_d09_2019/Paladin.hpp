/*
** EPITECH PROJECT, 2020
** Paladin
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin: public Warrior, public Priest
{
    public:
        Paladin(const std::string &, int16_t, const std::string newWeapon = "hammer");
        ~Paladin();
        using Warrior::CloseAttack;
        using Priest::RangeAttack;
        using Warrior::RestorePower;
        using Priest::Heal;
        int16_t Intercept();
};

#endif /* !PALADIN_HPP_ */
