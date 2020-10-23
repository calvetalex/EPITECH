/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** PapaXmasConveyorBelt
*/

#include "Conveyor/PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
}

AObject *PapaXmasConveyorBelt::pickUp()
{
    AObject *tmp = this->obj;

    obj = nullptr;
    return (tmp);
}

void PapaXmasConveyorBelt::putDown(AObject *new_obj)
{
    obj = new_obj;
    if (!obj)
        std::cerr << "There is no object here :(" << std::endl;
}

const bool PapaXmasConveyorBelt::isEmpty() const
{
    if (this->obj == nullptr)
        return true;
    return false;
}