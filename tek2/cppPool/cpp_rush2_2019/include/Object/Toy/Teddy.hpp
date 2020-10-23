/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** Teddy.hpp
*/

#ifndef TEDDY_HPP
    #define TEDDY_HPP

    #include <string>
    #include "IToy.hpp"

    class Teddy : public IToy {
        public:
            Teddy(Type typeObject, const std::string &title);
            Teddy(Teddy &cpy);
            ~Teddy();
            const bool isTaken(void) final;
            const std::string &getTitle(void) const final;

        protected :

        private :
    };

#endif /* !TEDDY_HPP */
