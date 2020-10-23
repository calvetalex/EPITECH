/*
** EPITECH PROJECT, 2020
** SickKoala
** File description:
** class declaration
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <string>

class SickKoala
{
    public:
        ~SickKoala();
        SickKoala(std::string);
        void poke(void);
        bool takeDrug(std::string);
        void overDrive(std::string);
        std::string getName(void);
    private:
        std::string _name;
};

#endif