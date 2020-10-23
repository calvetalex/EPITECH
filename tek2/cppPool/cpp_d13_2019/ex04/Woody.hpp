/*
** EPITECH PROJECT, 2020
** Woody
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody: public Toy {
    public:
        explicit Woody(const std::string &, const std::string & = "woody.txt");
        ~Woody();
        Woody &operator=(Woody &);
        void speak(const std::string&) override;
};

#endif /* !WOODY_HPP_ */
