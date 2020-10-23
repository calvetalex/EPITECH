/*
** EPITECH PROJECT, 2020
** GiftPaper
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
    #define GIFTPAPER_HPP_

    #include "Box.hpp"
    #include "AWrap.hpp"

    class GiftPaper: public AWrap {
        public:
            GiftPaper(Type);
            GiftPaper(GiftPaper &cpy);
            ~GiftPaper();
            void wrapMeThat(AObject *) final;
            AObject *takeOff(void) const final;

        private:
            Box *_boxWraped;
    };

#endif /* !GIFTPAPER_HPP_ */
