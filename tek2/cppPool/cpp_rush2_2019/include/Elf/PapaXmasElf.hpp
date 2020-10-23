/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#ifndef PAPA_XMAS_ELF_HPP_
    #define PAPA_XMAS_ELF_HPP_

    #include "AElf.hpp"

    class PapaXmasElf : public AElf {
        public :
            PapaXmasElf(){};
            PapaXmasElf(const PapaXmasTable &table, const PapaXmasConveyorBelt &conveyorBelt);
            ~PapaXmasElf();
            void pressIn(AObject *obj);
            AObject *pressOut();
            void takeNew(void);
            const bool checkPresent();

        protected :
            void writePresent(void);
            void deletePresent(void);

        private :
    };

#endif
