/*
** EPITECH PROJECT, 2020
** ITable
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
    #define ITABLE_HPP_

    #include <vector>
    #include "../Object/AObject.hpp"

    class ITable {
        public:
            virtual ~ITable() = default;

            virtual bool putObject(AObject *) = 0; // place object in the table
            virtual AObject *getObject(int) const = 0; // take an object in inventory
            virtual AObject *getFromType(AObject::Type) const = 0; // take an object by type
            virtual const bool isFull(void) const = 0; // check if table is full
            virtual void collapse(void) = 0; // break table

            virtual const std::vector<std::string> *look(void) const = 0; // get inventory (NOM IMPOSE par sujet)

        protected:
            std::vector<AObject *> _inventory;
    };

#endif /* !ITABLE_HPP_ */
