/*
** EPITECH PROJECT, 2020
** Priest
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest: public Mage
{
    public:
        Priest(const std::string &, int16_t);
        ~Priest();
        int16_t CloseAttack();
        void Heal();
};

#endif /* !PRIEST_HPP_ */
