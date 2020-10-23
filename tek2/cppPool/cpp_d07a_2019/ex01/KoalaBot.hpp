/*
** EPITECH PROJECT, 2020
** KoalaBot
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include <string>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string = "Bob-01");
        ~KoalaBot();
        void setParts(Arms &);
        void setParts(Legs &);
        void setParts(Head &);
        void swapParts(Arms&);
        void swapParts(Legs&);
        void swapParts(Head&);
        void informations(void) const;
        bool status(void) const;
    private:
        std::string _name;
        Arms _arms;
        Legs _legs;
        Head _head;
};

#endif /* !KOALABOT_HPP_ */
