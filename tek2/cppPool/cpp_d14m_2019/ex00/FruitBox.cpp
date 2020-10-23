/*
** EPITECH PROJECT, 2020
** FruitBox
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int16_t maxFruits)
{
    this->_maxFruits = maxFruits;
    this->_nbFruits = 0;
    this->_begin = nullptr;
}

FruitBox::~FruitBox()
{
}

int16_t FruitBox::nbFruits(void) const
{
    return this->_nbFruits;
}

FruitNode *FruitBox::head(void) const
{
    return this->_begin;
}

bool FruitBox::putFruit(Fruit *newFruit)
{
    FruitNode *tmp;
    FruitNode *newElem;

    if (this->_nbFruits >= this->_maxFruits)
        return false;
    if (!this->_begin) {
        this->_begin = new FruitNode;
        this->_begin->_fruit = newFruit;
        this->_begin->_next = nullptr;
        this->_nbFruits++;
        return true;
    }
    for (tmp = this->_begin; tmp->_next != nullptr; tmp = tmp->_next);
    if (tmp == nullptr)
        return false;
    newElem = new FruitNode;
    newElem->_fruit = newFruit;
    newElem->_next = nullptr;
    tmp->_next = newElem;
    this->_nbFruits++;
    return true;
}

Fruit *FruitBox::pickFruit(void)
{
    FruitNode *toRemove;
    Fruit *fruitGetted;

    if (!this->_begin)
        return nullptr;
    fruitGetted = this->_begin->_fruit;
    this->_begin = this->_begin->_next;
    toRemove = this->_begin->_next;
    delete toRemove;
    this->_nbFruits--;
    return fruitGetted;
}