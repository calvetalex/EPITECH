/*
** EPITECH PROJECT, 2020
** Toy
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy {
    public:
        typedef enum ToyType_e {
            BASIC_TOY,
            ALIEN
        } ToyType;

        Toy();
        ~Toy();
        Toy(Toy &);
        Toy(ToyType, const std::string &, const std::string &);
        Toy &operator=(const Toy&);

        const std::string getName(void) const;
        ToyType getType(void) const;
        const std::string getAscii(void) const;
        void setName(const std::string &);
        bool setAscii(const std::string &);
    private:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
