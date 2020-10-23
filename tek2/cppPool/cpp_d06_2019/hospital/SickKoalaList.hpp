/*
** EPITECH PROJECT, 2020
** SickKoalaList
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include <string>
#include "SickKoala.hpp"

class SickKoalaList {
	public:
		SickKoalaList(SickKoala *);
		~SickKoalaList();
        bool isEnd(void);
        void append(SickKoalaList *);
        SickKoala *getFromName(std::string);
        SickKoalaList *remove(SickKoalaList *);
        SickKoalaList *removeFromName(std::string);
        SickKoala *getContent(void);
        SickKoalaList *getNext(void);
        void dump(void);
	private:
        SickKoala *_value;
        SickKoalaList *_next;
};

#endif /* !SICKKOALALIST_HPP_ */
