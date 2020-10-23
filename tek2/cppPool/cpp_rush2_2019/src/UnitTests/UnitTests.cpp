/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** UnitTests
*/

#include "Object/Toy/LittlePony.hpp"
#include "Object/Toy/Teddy.hpp"
#include "Object/AObject.hpp"
#include "Elf/Elf.hpp"
#include "Elf/PapaXmasElf.hpp"
#include "Conveyor/PapaXmasConveyorBelt.hpp"
#include "Table/PapaXmasTable.hpp"
#include "Object/Wrap/Box.hpp"
#include "Object/Wrap/GiftPaper.hpp"

AObject **MyUnitTests(void)
{
    AObject **toys = new AObject *[2];
    toys[1] = new LittlePony(IObject::PONY, "happy pony");
    toys[2] = new Teddy(IObject::TEDDY, "cuddles");

    return toys;
}

AObject *MyUnitTests(AObject **objs)
{
    PapaXmasTable santaTable = PapaXmasTable();
    PapaXmasTable elfTable = PapaXmasTable();
    PapaXmasConveyorBelt santaCB = PapaXmasConveyorBelt();
    PapaXmasConveyorBelt elfCB = PapaXmasConveyorBelt();
    PapaXmasElf santaTMP(santaTable, santaCB);
    Elf worker(santaTMP, elfTable, elfCB);
    ((Box *)objs[1])->wrapMeThat(objs[0]);
    ((GiftPaper *)objs[1])->wrapMeThat(objs[1]);
    return objs[1];
}

PapaXmasTable *createTable(void)
{
    return new PapaXmasTable();
}

PapaXmasConveyorBelt *createConveyorBelt(void)
{
    return new PapaXmasConveyorBelt();
}
