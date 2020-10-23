/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Elf Interface
*/

#ifndef ELF_HPP_
    #define ELF_HPP_

    #include "AElf.hpp"
    #include "./Object/Wrap/GiftPaper.hpp"
    #include "PapaXmasElf.hpp"

    class Elf : public AElf {
        public :
            Elf();
            Elf(const PapaXmasElf &santa, const PapaXmasTable &table, const PapaXmasConveyorBelt &conveyorBelt);
            ~Elf();
            AObject *pressIn();
            void pressOut();
            void takeNew(void) final;
            GiftPaper *makePresent(void);

        protected :
            PapaXmasElf _santa;

        private :
    };

#endif