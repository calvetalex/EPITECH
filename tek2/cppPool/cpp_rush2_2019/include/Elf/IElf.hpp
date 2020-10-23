/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#ifndef I_ELF_HPP_
    #define I_ELF_HPP_

    #include "Object/AObject.hpp"
    #include "Conveyor/PapaXmasConveyorBelt.hpp"
    #include "Table/PapaXmasTable.hpp"
    #include "Hand.hpp"

    class IElf {
        public :

            enum Side {
                NONE = -1,
                LEFT = 0,
                RIGHT = 1
            };

            IElf() {};
            virtual ~IElf() = default;
            virtual void takeNew(void) = 0;
            virtual int takeObject(AObject::Type type, PapaXmasTable &table) = 0;
            virtual int takeObject(AObject::Type type, PapaXmasConveyorBelt &conveyorBelt) = 0;
            virtual void putObject(Side side, PapaXmasTable &table) = 0;
            virtual void putObject(Side side, PapaXmasConveyorBelt &conveyorBelt) = 0;
            virtual const PapaXmasConveyorBelt &getConveyorBelt() const = 0;
            virtual const PapaXmasTable &getTable() const = 0;

        protected :
            PapaXmasConveyorBelt _conveyorBelt;
            PapaXmasTable _table;
            std::vector<Hand *> _hands;
        private :
    };

#endif