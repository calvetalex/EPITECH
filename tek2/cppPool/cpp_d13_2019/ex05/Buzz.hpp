/*
** EPITECH PROJECT, 2020
** Buzz
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz: public Toy
{
    public:
        explicit Buzz(const std::string &, const std::string & = "buzz.txt");
        ~Buzz();
        Buzz &operator=(Buzz &);
        void speak(const std::string&) override;
        bool speak_es(const std::string&) override;
};

#endif /* !BUZZ_HPP_ */
