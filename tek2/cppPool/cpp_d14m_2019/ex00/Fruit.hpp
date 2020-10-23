/*
** EPITECH PROJECT, 2020
** Fruit
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>
#include <cstdint>

class Fruit {
    public:
        ~Fruit();
        Fruit &operator=(const Fruit&);

        std::string getName(void) const;
        int16_t getVitamins(void) const;

        void setName(std::string &);
        void setVitamins(int16_t);
    protected:
        int16_t _vitamins;
        std::string _name;

        explicit Fruit(const std::string&, int16_t);
        Fruit(const Fruit&);
};

#endif /* !FRUIT_HPP_ */
