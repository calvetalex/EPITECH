/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#ifndef A_ELF_HPP_
    #define A_ELF_HPP_

    #include "./Conveyor/IConveyorBelt.hpp"
    #include "./Table/ITable.hpp"
    #include "IElf.hpp"

    class AElf : public IElf {
        public :
            AElf(){};
            AElf(const PapaXmasTable &table, const PapaXmasConveyorBelt &conveyorBelt);
            virtual ~AElf();
            virtual void takeNew(void) = 0;
            int takeObject(AObject::Type, PapaXmasTable &table) final;
            int takeObject(AObject::Type, PapaXmasConveyorBelt &conveyorBelt) final;
            void putObject(Side side, PapaXmasTable &table) final;
            void putObject(Side side, PapaXmasConveyorBelt &conveyorBelt) final;
            const PapaXmasConveyorBelt &getConveyorBelt() const;
            const PapaXmasTable &getTable() const;

        protected :

        private :
    };

#endif