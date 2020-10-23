/*
** EPITECH PROJECT, 2020
** Character
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <cstring>
#include <iostream>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
    public:
        Character(const std::string &);
        ~Character();

        void recoverAP(void);
        void equip(AWeapon *);
        void attack(AEnemy *);

        std::string getName(void) const { return _name; };
        int16_t getAp(void) const { return _ap; };
        AWeapon *getWeapon(void) const { return _gun; };
    protected:
        std::string _name;
        int16_t _ap;
        AWeapon *_gun;
};

std::ostream &operator<<(std::ostream &, Character &);

#endif /* !CHARACTER_HPP_ */
