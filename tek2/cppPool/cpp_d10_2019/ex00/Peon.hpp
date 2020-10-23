/*
** EPITECH PROJECT, 2020
** PEON
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include <string>
#include "Victim.hpp"

class Peon: public Victim
{
    public:
        explicit Peon(const std::string &);
        ~Peon();
        void getPolymorphed(void) const override;
};

#endif /* !PEON_HPP_ */
