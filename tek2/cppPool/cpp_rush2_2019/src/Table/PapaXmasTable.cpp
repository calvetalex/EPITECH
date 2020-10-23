/*
** EPITECH PROJECT, 2020
** PapaXmasTable
** File description:
** PapaXmasTable
*/

// #include <bits/stdc++.h>
#include <iostream>
#include "Table/PapaXmasTable.hpp"
#include "Object/Toy/LittlePony.hpp"
#include "Object/Toy/Teddy.hpp"


PapaXmasTable::PapaXmasTable()
{
}

PapaXmasTable::~PapaXmasTable()
{
}


AObject *PapaXmasTable::getObject(int place) const
{
    return this->_inventory.at(place);
}

AObject *PapaXmasTable::getFromType(AObject::Type typeToGet) const
{
    int i = 0;
    int max = this->_inventory.size();
    AObject *tmp = nullptr;

    while(i < max && this->_inventory.at(i)->getType() != typeToGet)
    {
        i++;
    }

    if (this->_inventory.at(i)->getType() == typeToGet) {
        tmp = this->_inventory.at(i);
        ((std::vector<AObject*>)this->_inventory).erase(this->_inventory.begin() + i);
        return (tmp);
    }
    return (nullptr);
}

const bool PapaXmasTable::isFull(void) const
{
    if (this->_inventory.size() < 10)
        return false;
    return true;
}

void PapaXmasTable::collapse(void)
{
    this->_inventory.clear();
    this->_inventory.shrink_to_fit();
    this->~PapaXmasTable();
}

const std::vector<std::string> *PapaXmasTable::look(void) const
{
    std::vector<std::string> *list = new std::vector<std::string>();

    for (auto it = _inventory.begin(); it < _inventory.end(); it++) {
        if ((*it)->getType() == IObject::PONY)
            list->push_back(((LittlePony *)*it)->getTitle());
        else if ((*it)->getType() == IObject::TEDDY)
            list->push_back(((Teddy *)*it)->getTitle());
    }
    return list;
}

bool PapaXmasTable::putObject(AObject *newObj)
{
    if (!this->isFull()) {
        this->_inventory.push_back(newObj);
        return true;
    }
    std::cerr << "No more place on the Table!" << std::endl;
    return false;
}