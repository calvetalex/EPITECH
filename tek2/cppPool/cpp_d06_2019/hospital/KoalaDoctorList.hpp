/*
** EPITECH PROJECT, 2020
** KoalaDoctorList
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include <string>
#include "KoalaDoctor.hpp"

class KoalaDoctorList {
	public:
		KoalaDoctorList(KoalaDoctor *);
		~KoalaDoctorList();
        bool isEnd(void);
        void append(KoalaDoctorList *);
        KoalaDoctor *getFromName(std::string);
        KoalaDoctorList *remove(KoalaDoctorList *);
        KoalaDoctorList *removeFromName(std::string);
        void dump(void);
	private:
        KoalaDoctor *_value;
        KoalaDoctorList *_next;
};

#endif /* !KOALADOCTORLIST_HPP_ */