

#include <iostream>
#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doc): _value(doc), _next(nullptr)
{
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd(void)
{
    return (this->_next == nullptr);
}

void KoalaDoctorList::append(KoalaDoctorList *to_add)
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

KoalaDoctor *KoalaDoctorList::getFromName(std::string nameSearched)
{
    if (this->_value->getName() == nameSearched)
        return (this->_value);
    if (!this->_next)
        return nullptr;
    return (this->_next->getFromName(nameSearched));
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *to_rm)
{
	for (KoalaDoctorList *current = this, *previous = nullptr; current; current = current->_next) {
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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string to_rm)
{

	for (KoalaDoctorList *current = this, *previous = nullptr; current; current = current->_next) {
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

void KoalaDoctorList::dump(void)
{
    std::cout << "Doctors: ";
	for (KoalaDoctorList *current = this; current; current = current->_next) {
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