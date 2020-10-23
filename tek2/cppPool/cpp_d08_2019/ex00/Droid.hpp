/*
** EPITECH PROJECT, 2020
** Droid
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <ostream>
#include <string>

class Droid {
    public:
        Droid(std::string = "");
        Droid(Droid const &);
        ~Droid();
        void setId(std::string);
        void setEnergy(size_t);
        void setStatus(std::string *);
        std::string getId(void) const { return this->Id; };
        size_t getEnergy(void) const { return this->Energy; };
        size_t getAttack(void) const { return this->Attack; };
        size_t getToughness(void) const { return this->Toughness; };
        std::string *getStatus(void) const { return this->Status; };
        Droid &operator=(Droid const &);
        Droid &operator<<(size_t&);
        bool operator!=(Droid const &) const;
        bool operator==(Droid const &) const;
    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
};

std::ostream& operator<<(std::ostream&, const Droid &);

#endif /* !DROID_HPP_ */
