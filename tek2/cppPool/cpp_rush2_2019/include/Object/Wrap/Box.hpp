/*
** EPITECH PROJECT, 2020
** Box
** File description:
** Box
*/

#ifndef BOX_HPP_
    #define BOX_HPP_

    #include "AWrap.hpp"
    #include "Object/Toy/IToy.hpp"

    class Box: public AWrap {
        public:
            Box(Type);
            Box(Box &cpy);
            ~Box();
            void wrapMeThat(AObject *) final;
            AObject *takeOff(void) const final;

        private:
            AObject *_toyInside;
    };

#endif /* !BOX_HPP_ */
