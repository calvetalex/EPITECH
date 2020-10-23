/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** IToy
*/

#ifndef ITOY_HPP
    #define ITOY_HPP

    #include <string>

    #include "Object/AObject.hpp"

    class IToy : public AObject {
        public:
            IToy(Type typeObject) : AObject(typeObject) {};
            virtual ~IToy() = default;
            virtual const bool isTaken(void) = 0;
            virtual const std::string &getTitle(void) const = 0;

        protected:
            bool pickUp;
            std::string _title;

        private:
    };

#endif /* !ITOY_HPP */
