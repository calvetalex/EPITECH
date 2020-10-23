/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#ifndef I_HAND_HPP_
    #define I_HAND_HPP_

    #include "Object/AObject.hpp"

    class IHand {
        public :
            virtual ~IHand() = default;
            virtual const bool isUsed(void) const = 0;
            virtual void setObject(AObject *obj) = 0;
            virtual AObject *getObject(void) = 0;

        protected :
            AObject *_carriedObject;

        private :
    };

#endif