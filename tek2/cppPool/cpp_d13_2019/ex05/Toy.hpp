/*
** EPITECH PROJECT, 2020
** Toy
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        typedef enum ToyType_e {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        } ToyType;

        class Error {
            public:
                typedef enum ErrorType_e {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                }ErrorType;
                Error();
                std::string what(void) const;
                std::string where(void) const;

                ErrorType_e type;
        };

        Toy();
        ~Toy();
        Toy(Toy &);
        Toy(ToyType, const std::string &, const std::string &);
        Toy &operator=(const Toy&);

        virtual void speak(const std::string &);
        virtual bool speak_es(const std::string &);
        Toy &operator<<(const std::string&);

        Error getLastError(void);

        const std::string getName(void) const;
        ToyType getType(void) const;
        Error getError(void) const;
        const std::string getAscii(void) const;
        void setName(const std::string &);
        bool setAscii(const std::string &);
    protected:
        ToyType _type;
        std::string _name;
        Picture _picture;
        Error _error;
};

std::ostream &operator<<(std::ostream &, const Toy&);

#endif /* !TOY_HPP_ */
