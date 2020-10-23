/*
** EPITECH PROJECT, 2020
** KoalaNurse
** File description:
** KoalaNurse Class
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <cstdint>
#include <string>
#include "SickKoala.hpp"
class KoalaNurse {
    public:
        KoalaNurse(uint16_t);
        ~KoalaNurse();
        void giveDrug(std::string, SickKoala *);
        std::string readReport(std::string);
        void timeCheck(void);
        uint16_t getID(void);
    private:
        uint16_t _id;
        bool _isWorking;
};

#endif /* !KOALANURSE_HPP_ */
