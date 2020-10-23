/*
** EPITECH PROJECT, 2020
** VICTIM
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>
#include <string>

class Victim {
    public:
        explicit Victim(const std::string &);
        ~Victim();
        virtual void getPolymorphed() const;

        const std::string &getName() const { return _name; };
    protected:
        std::string _name;
};

std::ostream& operator<<(std::ostream &, const Victim&);

#endif /* !VICTIM_HPP_ */
