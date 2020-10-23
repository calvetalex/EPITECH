/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** LittlePony.hpp
*/

#ifndef LITTLEPONY_HPP
    #define LITTLEPONY_HPP

    #include <string>
    #include "Object/AObject.hpp"
    #include "IToy.hpp"

    class LittlePony: public IToy {
        public:
            explicit LittlePony(Type typeObject, const std::string &title);
            LittlePony(LittlePony &cpy);
            ~LittlePony();
            const bool isTaken(void) final;
            const std::string &getTitle(void) const final;

        protected:

        private:
    };

#endif /* !LITTLEPONY_HPP */
