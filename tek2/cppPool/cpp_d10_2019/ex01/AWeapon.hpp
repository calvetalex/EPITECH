/*
** EPITECH PROJECT, 2020
** AWepon
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <string>
#include <cstring>

class AWeapon {
    public:
        AWeapon(const std::string&, int16_t, int16_t);
        ~AWeapon();
        std::string getName(void) const { return _name; };
        int16_t getAPCost() const { return _apcost; };
        int16_t getDamage() const { return _damage; };
        virtual void attack() const = 0;
    protected:
        std::string _name;
        int16_t _apcost;
        int16_t _damage;
};

#endif /* !AWEAPON_HPP_ */
