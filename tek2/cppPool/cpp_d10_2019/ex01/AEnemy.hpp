/*
** EPITECH PROJECT, 2020
** AEnemey
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <string>
#include <cstring>

class AEnemy {
    public:
        AEnemy(int16_t, const std::string&);
        virtual ~AEnemy();
        virtual void takeDamage(int16_t);

        int16_t getHP(void) const { return _hp; };
        std::string getType(void) const { return _type; };
    protected:
        int16_t _hp;
        std::string _type;
};

#endif /* !AENEMY_HPP_ */
