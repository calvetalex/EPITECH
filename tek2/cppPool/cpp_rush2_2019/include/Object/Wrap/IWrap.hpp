/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** IWrap
*/

#ifndef IWRAP_HPP_
    #define IWRAP_HPP_

    #include "Object/AObject.hpp"

    class IWrap : public AObject {
        public:
            IWrap() {};
            virtual ~IWrap() = default;

            virtual void wrapMeThat(AObject *) = 0;
            virtual void closeMe(void) = 0;
            virtual void openMe(void) = 0;
            virtual void setEmpty(bool) = 0;
            virtual void setOpen(bool) = 0;
            virtual const bool getEmpty() const = 0;
            virtual const bool getOpen() const = 0;
            virtual AObject *takeOff(void) const = 0;

        protected:
            bool _isEmpty;
            bool _isOpen;
    };

#endif /* !IWRAP_HPP_ */
