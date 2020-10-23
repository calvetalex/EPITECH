/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** IConveyorBelt
*/

#ifndef ICONVEYORBELT_HPP_
	#define ICONVEYORBELT_HPP_

    #include <string>
    #include "Object/AObject.hpp"

    class IConveyorBelt {
        public:
            virtual ~IConveyorBelt() = default;

            virtual AObject *pickUp() = 0;
            virtual void putDown(AObject *) = 0;
            virtual const bool isEmpty() const = 0;

        protected:
            AObject *obj;
    };

#endif /* !ICONVEYORBELT_HPP_ */