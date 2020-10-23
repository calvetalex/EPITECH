/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#include <iostream>
#include <random>
#include "./Object/Toy/Teddy.hpp"
#include "./Object/Toy/LittlePony.hpp"
#include "Elf/Elf.hpp"
#include "Elf/PapaXmasElf.hpp"

Elf::Elf(const PapaXmasElf &santa, const PapaXmasTable &table, const PapaXmasConveyorBelt &conveyorBelt) : AElf(table, conveyorBelt)
{
    _santa = santa;
}

Elf::~Elf()
{
}

AObject *Elf::pressIn()
{
    return (_santa.pressOut());
}

void Elf::pressOut()
{
    _santa.pressIn(_conveyorBelt.pickUp());
}

void Elf::takeNew(void)
{
    AObject *toy = nullptr;

    if (_hands.at(0)->isUsed() == true && _hands.at(1)->isUsed() == true) {
        std::cerr << "Sorry, my hands are full. I can't take a new toy." << std::endl;
        return;
    }
    if (random() % 2 == 0)
        toy = new Teddy(AObject::TEDDY, "teddy");
    else
        toy = new LittlePony(AObject::PONY, "pony");
    if (_table.isFull() == false)
        _table.putObject(toy);
    else {
        if (_hands.at(0)->isUsed() == false)
            _hands.at(0)->setObject(toy);
        else
            _hands.at(1)->setObject(toy);
    }
    return;
}

GiftPaper *Elf::makePresent(void)
{
    int freeHand = this->_hands.at(0)->isUsed() ? 1 : 0;
    Box *usedBox = nullptr;
    AObject *toy = nullptr;
    GiftPaper *usedGiftPaper = nullptr;

    while (!(usedBox = (Box*)this->_table.getFromType(AObject::BOX)) && !this->_table.isFull()) {
        this->pressIn();
        this->_hands.at(freeHand)->setObject(this->_conveyorBelt.pickUp());
        this->_table.putObject(this->_hands.at(freeHand)->getObject());
    }
    if (this->_table.isFull()) {
        std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
        exit(0);
    }
    usedBox->openMe();
    toy = this->_table.getFromType(AObject::TEDDY);
    if (toy == nullptr)
        toy = this->_table.getFromType(AObject::PONY);
    this->_hands.at(freeHand)->setObject(toy);
    usedBox->wrapMeThat(this->_hands.at(freeHand)->getObject());
    usedBox->closeMe();
    while (!(usedGiftPaper = (GiftPaper*)this->_table.getFromType(AObject::GIFTPAPER)) && !this->_table.isFull()) {
        this->pressIn();
        this->_hands.at(freeHand)->setObject(this->_conveyorBelt.pickUp());
        this->_table.putObject(this->_hands.at(freeHand)->getObject());
    }
    if (this->_table.isFull()) {
        std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
        exit(0);
    }
    usedGiftPaper->wrapMeThat(usedBox);
    std::cout << "e speex'n'XML" << std::endl;
    return (usedGiftPaper);
}