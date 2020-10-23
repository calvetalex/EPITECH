/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** AWrap
*/

#ifndef AWRAP_HPP_
    #define AWRAP_HPP_

    #include "IWrap.hpp"

    class AWrap : public IWrap {
        public :
            AWrap();
            ~AWrap();

            void closeMe(void) final;
            void openMe(void) final;
            void setEmpty(bool) final;
            void setOpen(bool) final;
            const bool getEmpty() const final;
            const bool getOpen() const final;
            virtual void wrapMeThat(AObject *) = 0;
            virtual AObject *takeOff(void) const = 0;

        protected :

        private :
    };

#endif /* !AWRAP_HPP_ */
