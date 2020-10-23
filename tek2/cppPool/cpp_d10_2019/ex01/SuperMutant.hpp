/*
** EPITECH PROJECT, 2020
** SuperMutant
** File description:
** SuperMutant
*/

#ifndef SUPERMUTANT_HPP_
#define SUPERMUTANT_HPP_

#include "AEnemy.hpp"

class SuperMutant: public AEnemy {
    public:
        SuperMutant();
        ~SuperMutant();
        void takeDamage(int16_t) override;
};

#endif /* !SUPERMUTANT_HPP_ */
