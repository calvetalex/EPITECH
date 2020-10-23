/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#ifndef HAND_HPP_
    #define HAND_HPP_

    #include "IHand.hpp"

    class Hand : public IHand {
        public :
            Hand();
            ~Hand();
            const bool isUsed(void) const final;
            void setObject(AObject *obj) final;
            AObject *getObject(void) final;

        protected :

        private :
    };

#endif