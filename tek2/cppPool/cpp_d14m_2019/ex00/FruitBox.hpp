/*
** EPITECH PROJECT, 2020
** FruitBox.hpp
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include <cstdint>
#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        explicit FruitBox(int16_t);
        ~FruitBox();

        int16_t nbFruits(void) const;
        FruitNode *head(void) const;

        bool putFruit(Fruit *);
        Fruit *pickFruit(void);
    private:
        int16_t _nbFruits;
        int16_t _maxFruits;
        FruitNode *_begin;
};

#endif /* !FRUITBOX_HPP_ */
