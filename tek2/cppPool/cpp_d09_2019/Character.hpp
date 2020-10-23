/*
** EPITECH PROJECT, 2020
** Family matters
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <cstdint>

class Character {
    public:
        typedef enum AttackRange_e {
            CLOSE,
            RANGE,
        } AttackRange;

    public:
        explicit Character(const std::string&, int16_t);
        ~Character();
        // Get functions
        const std::string &getName() const { return _name; };
        int16_t getLvl() const { return _level; };
        int16_t getPv() const { return _pv; };
        int16_t getPower() const { return _power; };
        const std::string getRace() const {return _race; };
        int16_t getStrength() const { return _strength; };
        int16_t getStamina() const { return _stamina; };
        int16_t getIntelligence() const { return _intelligence; };
        int16_t getSpirit() const { return _spirit; };
        int16_t getAgility() const { return _agility; };
        // Fight functions
        int16_t CloseAttack();
        int16_t RangeAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int16_t);
        // Range
        AttackRange Range;
    protected:
        std::string _name;
        int16_t _level;
        int16_t _pv;
        int16_t _power;
        std::string _race;
        int16_t _strength;
        int16_t _stamina;
        int16_t _intelligence;
        int16_t _spirit;
        int16_t _agility;
};

#endif /* !CHARACTER_HPP_ */
