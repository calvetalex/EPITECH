/*
** EPITECH PROJECT, 2020
** SickKoalaList
** File description:
** SickKoalaList
*/

#include <iostream>
#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *patient): _value(patient), _next(nullptr)
{
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd(void)
{
    return (this->_next == nullptr);
}

void SickKoalaList::append(SickKoalaList *to_add)
{
    if (!this->_next && !this->_value) {
        this->_value = to_add->_value;
        this->_next = to_add->_next;
    } else if (!this->_next) {
        this->_next = to_add;
		this->_next->_next = nullptr;
	} else
        _next->append(to_add);
}

SickKoala *SickKoalaList::getFromName(std::string nameSearched)
{
    if (this->_value->getName() == nameSearched)
        return (this->_value);
    if (!this->_next)
        return nullptr;
    return (this->_next->getFromName(nameSearched));
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *to_rm)
{
	for (SickKoalaList *current = this, *previous = nullptr; current; current = current->_next) {
		if (current == to_rm) {
			if (previous) {
				previous->_next = current->_next;
				current->_next = nullptr;
				return this;
			} else {
				previous = current->_next;
				current->_next = nullptr;
				return previous;
			}
		}
		previous = current;
	}
	return nullptr;
}

SickKoalaList *SickKoalaList::removeFromName(std::string to_rm)
{

	for (SickKoalaList *current = this, *previous = nullptr; current; current = current->_next) {
		if (current->_value && current->_value->getName() == to_rm) {
			if (previous) {
				previous->_next = current->_next;
				current->_next = nullptr;
				return this;
			} else {
				previous = current->_next;
				current->_next = nullptr;
				return previous;
			}
		}
		previous = current;
	}
	return nullptr;
}

SickKoala *SickKoalaList::getContent()
{
    return (this->_value);
}

SickKoalaList *SickKoalaList::getNext(void)
{
    return (this->_next);
}

void SickKoalaList::dump(void)
{
    std::cout << "Patients : ";
	for (SickKoalaList *current = this; current; current = current->_next) {
		if (current->_value)
			std::cout << current->_value->getName();
		else
			std::cout << "NULL";
		if (current->_next)
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
	}
}