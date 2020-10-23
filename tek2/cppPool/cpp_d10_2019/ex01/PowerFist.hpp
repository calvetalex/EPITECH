/*
** EPITECH PROJECT, 2020
** PowerFist
** File description:
** PowerFist
*/

#ifndef POWERFIST_HPP_
#define POWERFIST_HPP_

#include "AWeapon.hpp"

class PowerFist: public AWeapon {
    public:
        PowerFist();
        ~PowerFist();
        void attack() const override;
};

#endif /* !POWERFIST_HPP_ */
