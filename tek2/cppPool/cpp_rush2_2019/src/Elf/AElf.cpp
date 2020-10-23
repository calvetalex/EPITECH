/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#include "Elf/AElf.hpp"
#include "Elf/Hand.hpp"

AElf::AElf(const PapaXmasTable &table, const PapaXmasConveyorBelt &conveyorBelt) : IElf()
{
    _table = table;
    _conveyorBelt = conveyorBelt;
    _hands.push_back(new Hand());
    _hands.push_back(new Hand());
}

AElf::~AElf()
{
}

int AElf::takeObject(AObject::Type typeToGet, PapaXmasTable &table)
{
    if (_hands[LEFT]->isUsed() == true) {
        _hands[LEFT]->setObject(table.getFromType(typeToGet));
        return (LEFT);
    } else if (_hands[RIGHT]->isUsed() == true) {
        _hands[RIGHT]->setObject(table.getFromType(typeToGet));
        return (RIGHT);
    } else
        return (NONE);
}

void AElf::putObject(Side side, PapaXmasTable &table)
{
    table.putObject(_hands[side]->getObject());
    return;
}

int AElf::takeObject(AObject::Type type, PapaXmasConveyorBelt &conveyorBelt)
{
    if (_hands[LEFT]->isUsed() == true) {
        _hands[LEFT]->setObject(conveyorBelt.pickUp());
        return (LEFT);
    } else if (_hands[RIGHT]->isUsed() == true) {
        _hands[RIGHT]->setObject(conveyorBelt.pickUp());
        return (RIGHT);
    } else
        return (NONE);
}

void AElf::putObject(Side side, PapaXmasConveyorBelt &conveyorBelt)
{
    conveyorBelt.putDown(_hands[side]->getObject());
    return;
}

const PapaXmasConveyorBelt &AElf::getConveyorBelt() const
{
    return (_conveyorBelt);
}

const PapaXmasTable &AElf::getTable() const
{
    return (_table);
}