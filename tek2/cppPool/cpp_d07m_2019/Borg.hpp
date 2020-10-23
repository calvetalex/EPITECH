/*
** EPITECH PROJECT, 2020
** Borg
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

namespace Borg {
    class Ship;
}

#include <cstdint>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Federation.hpp"

namespace Borg {
    class Ship {
        public:
            Ship(int16_t = 20, int16_t = 3);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore(void);
            bool move(int16_t, Destination);
            bool move(int16_t);
            bool move(Destination);
            bool move(void);
            int16_t getShield(void);
            void setShield(int16_t);
            int16_t getWeaponFrequency(void);
            void setWeaponFrequency(int16_t);
            short getRepair(void);
            void setRepair(short);
            void fire(Federation::Starfleet::Ship *);
            void fire(Federation::Ship *);
            void repair(void);
        private:
            uint16_t _size;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int16_t _shield;
            short _repair;
            int16_t _weaponFrequency;
    };
}

#endif /* !BORG_HPP_ */
