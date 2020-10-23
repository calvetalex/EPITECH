/*
** EPITECH PROJECT, 2020
** Federation
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

namespace Federation {
    namespace Starfleet {
        class Ship;
    }
    class Ship;
}

#include <cstdint>
#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation {
    namespace Starfleet {
        class Ensign {
            public:
                explicit Ensign(std::string);
                ~Ensign();
            private:
            std::string _name;
        };
        class Captain {
            public:
                Captain(std::string);
                ~Captain();
                std::string getName(void);
                int16_t getAge(void);
                void setAge(int16_t);

            private:
                std::string _name;
                int _age;
        };
        class Ship {
            public:
                Ship(int16_t, int16_t, std::string, short, int16_t = 0);
                Ship();
                ~Ship();
                void setupCore(WarpSystem::Core *);
                void checkCore(void);
                void promote(Captain *);
                bool move(int16_t, Destination);
                bool move(int16_t);
                bool move(Destination);
                bool move(void);
                int16_t getShield(void);
                void setShield(int16_t);
                int16_t getTorpedo(void);
                void setTorpedo(int16_t);
                void fire(Borg::Ship *);
                void fire(int16_t, Borg::Ship *);
            private:
                int16_t _length;
                int16_t _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_shipCore;
                Captain *_captain;
                Destination _home;
                Destination _location;
                int16_t _shield;
                int16_t _photonTorpedo;
        };
    };
    class Ship {
        public:
            Ship(int16_t, int16_t, std::string);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore(void);
            bool move(int16_t, Destination);
            bool move(int16_t);
            bool move(Destination);
            bool move(void);
            int16_t getShield(void);
            void setShield(int16_t);
            int16_t getTorpedo(void);
            void setTorpedo(int16_t);
            WarpSystem::Core *getCore(void);
        private:
            int16_t _length;
            int16_t _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_shipCore;
            Destination _home;
            Destination _location;
            int16_t _shield;
            int16_t _photonTorpedo;
    };
}

#endif /* !FEDERATION_HPP_ */
