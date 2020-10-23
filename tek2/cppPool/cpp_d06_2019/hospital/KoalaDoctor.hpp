/*
** EPITECH PROJECT, 2020
** KoalaDoctor
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <string>
#include "SickKoala.hpp"

class KoalaDoctor
{
    public:
        KoalaDoctor(std::string);
        ~KoalaDoctor();
        void diagnose(SickKoala *);
        void timeCheck(void);
        std::string getName(void);
    private:
        std::string _name;
        bool _isWorking;
};

#endif /* !KOALADOCTOR_HPP_ */
