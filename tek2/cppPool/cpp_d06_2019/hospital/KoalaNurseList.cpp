/*
** EPITECH PROJECT, 2020
** KoalaNurseList
** File description:
** KoalaNurseList
*/

#include <iostream>
#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *patient): _value(patient), _next(nullptr)
{
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd(void)
{
    return (this->_next == nullptr);
}

void KoalaNurseList::append(KoalaNurseList *to_add)
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

KoalaNurse *KoalaNurseList::getFromID(uint16_t id)
{
    if (this->_value->getID() == id)
        return (this->_value);
    if (!this->_next)
        return nullptr;
    return (this->_next->getFromID(id));
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *to_rm)
{
	for (KoalaNurseList *current = this, *previous = nullptr; current; current = current->_next) {
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

KoalaNurseList *KoalaNurseList::removeFromID(uint16_t to_rm)
{

	for (KoalaNurseList *current = this, *previous = nullptr; current; current = current->_next) {
		if (current->_value && current->_value->getID() == to_rm) {
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

void KoalaNurseList::dump(void)
{
    std::cout << "Nurses: ";
	for (KoalaNurseList *current = this; current; current = current->_next) {
		if (current->_value)
			std::cout << current->_value->getID();
		else
			std::cout << "NULL";
		if (current->_next)
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
	}
}