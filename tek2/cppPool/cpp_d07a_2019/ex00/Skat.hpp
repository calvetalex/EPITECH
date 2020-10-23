/*
** EPITECH PROJECT, 2020
** Skat
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <cstdint>
#include <string>

class Skat {
    public:
        Skat(const std::string &name = "bob", int16_t stimPaks = 15);
        ~Skat();
        int16_t &stimPaks(void);
        const std::string &name();
        void shareStimPaks(int16_t number, int16_t &stock);
        void addStimPaks(uint16_t number);
        void useStimPaks(void);
        void status(void);
    private:
        std::string _name;
        int16_t _stimPaks;
};

#endif /* !SKAT_HPP_ */
