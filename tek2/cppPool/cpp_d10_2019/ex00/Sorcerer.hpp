/*
** EPITECH PROJECT, 2020
** Sorcerer
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer {
    public:
        explicit Sorcerer(const std::string&, const std::string&);
        ~Sorcerer();
        const std::string &getName() const { return _name; };
        const std::string &getTitle() const { return _title; };
        void polymorph(const Victim &) const;
    private:
        std::string _name;
        std::string _title;
};

std::ostream& operator<<(std::ostream&, Sorcerer const &);

#endif /* !SORCERER_HPP_ */
