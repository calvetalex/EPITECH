/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#include <iostream>
#include "Elf/PapaXmasElf.hpp"
#include "./Object/Wrap/Box.hpp"
#include "./Object/Wrap/GiftPaper.hpp"
#include "Xml/Xml.hpp"
#include "Object/Toy/LittlePony.hpp"
#include "Object/Toy/Teddy.hpp"

PapaXmasElf::PapaXmasElf(const PapaXmasTable &table, const PapaXmasConveyorBelt &conveyorBelt) : AElf(table, conveyorBelt)
{
}

PapaXmasElf::~PapaXmasElf()
{
}

void PapaXmasElf::pressIn(AObject *obj)
{
    if (_conveyorBelt.isEmpty() == false) {
        std::cout << "Conveyor Broke" << std::endl;
        exit(-1);
    }
    _conveyorBelt.putDown(obj);
    if (_hands.at(0)->isUsed() == false)
        _hands.at(0)->setObject(_conveyorBelt.pickUp());
    else if (_hands.at(1)->isUsed() == false)
        _hands.at(1)->setObject(_conveyorBelt.pickUp());
    else
        return;
    if (_table.isFull() == false) {
        if (_hands.at(0)->isUsed() == false)
            _hands.at(0)->setObject(_conveyorBelt.pickUp());
        else
            _hands.at(1)->setObject(_conveyorBelt.pickUp());
    }
    return;

}

AObject *PapaXmasElf::pressOut()
{
    takeNew();
    if (_hands.at(0)->isUsed() == true )
        return (_hands.at(0)->getObject());
    else if (_hands.at(1)->isUsed() == true)
        return (_hands.at(1)->getObject());
    else
        return (nullptr);
}

void PapaXmasElf::takeNew(void)
{
    AObject *wrap = nullptr;

    if (_hands.at(0)->isUsed() == true && _hands.at(1)->isUsed() == true) {
        std::cerr << "Sorry, my hands are full. I can't take a new wrapper." << std::endl;
        return;
    }
    if (random() % 2 == 0)
        wrap = new GiftPaper(AObject::TEDDY);
    else
        wrap = new Box(AObject::PONY);
    if (_table.isFull() == false)
        _table.putObject(wrap);
    else {
        if (_hands.at(0)->isUsed() == false)
            _hands.at(0)->setObject(wrap);
        else
            _hands.at(1)->setObject(wrap);
    }
    return;
}

const bool PapaXmasElf::checkPresent(void)
{
    GiftPaper *present = (GiftPaper *) _table.getFromType(AObject::GIFTPAPER);
    Box *boxPresent = nullptr;
    std::string serialized;
    Xml serializer;
    std::string type;
    std::string title;
    AObject *tmp;

    present->openMe();
    _hands.at(0)->setObject(present->takeOff());
    if (_table.isFull())
        return false;
    _table.putObject(_hands.at(0)->getObject());
    boxPresent = (Box *)_table.getFromType(AObject::BOX);
    boxPresent->openMe();
    if (boxPresent->getEmpty())
        return false;
    type = boxPresent->getType() == AObject::PONY ? "PONY" : "TEDDY";
        if (type == "PONY") {
            tmp = ((LittlePony *) boxPresent->takeOff());
            title = ((LittlePony *)tmp)->getTitle();
        } else {
            tmp = ((Teddy *) boxPresent->takeOff());
            title = ((Teddy *)tmp)->getTitle();
        }
    boxPresent->wrapMeThat(tmp);
    boxPresent->closeMe();
    present->wrapMeThat(boxPresent);
    present->closeMe();
    serialized = serializer.serialize(type, title);
    delete(present);
    std::cout << "Incoming Gift!" << std::endl << serialized << std::endl;
    return true;
}
