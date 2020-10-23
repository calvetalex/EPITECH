/*
** EPITECH PROJECT, 2020
** FruitNode
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

class FruitNode {
    public:
        Fruit *_fruit;
        FruitNode *_next;
};

#endif /* !FRUITNODE_HPP_ */
