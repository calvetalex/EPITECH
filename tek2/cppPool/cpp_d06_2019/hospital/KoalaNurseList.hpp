/*
** EPITECH PROJECT, 2020
** KoalaNurseList
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include <string>
#include <cstdint>
#include "KoalaNurse.hpp"

class KoalaNurseList {
	public:
        KoalaNurseList(KoalaNurse *);
        ~KoalaNurseList();
        bool isEnd(void);
        void append(KoalaNurseList *);
        KoalaNurse *getFromID(uint16_t);
        KoalaNurseList *remove(KoalaNurseList *);
        KoalaNurseList *removeFromID(uint16_t);
        void dump(void);
	private:
        KoalaNurse *_value;
        KoalaNurseList *_next;
};

#endif /* !KOALANURSELIST_HPP_ */