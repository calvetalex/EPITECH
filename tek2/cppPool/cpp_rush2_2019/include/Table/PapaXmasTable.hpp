/*
** EPITECH PROJECT, 2020
** PapaXmasTable
** File description:
** PapaXmasTable
*/

#ifndef PAPAXMASTABLE_HPP_
    #define PAPAXMASTABLE_HPP_

    #include "ITable.hpp"

    class PapaXmasTable: virtual public ITable {
        public:
            PapaXmasTable();
            ~PapaXmasTable();
            bool putObject(AObject *) final;
            AObject *getObject(int) const final;
            AObject *getFromType(AObject::Type) const final;
            bool const isFull(void) const final;
            void collapse(void) final;

            const std::vector<std::string> *look(void) const final;
    };

#endif /* !PapaXmasTable_HPP_ */
