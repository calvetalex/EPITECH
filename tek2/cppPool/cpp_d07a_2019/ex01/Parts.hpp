/*
** EPITECH PROJECT, 2020
** Parts
** File description:
** Parts
*/


#ifndef PARTS_H_
# define PARTS_H_

#include <string>

class Arms {
    public:
        Arms(std::string = "A-01", bool = true);
        ~Arms();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _isFunctionnal;
};
class Legs {
    public:
        Legs(std::string = "L-01", bool = true);
        ~Legs();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _isFunctionnal;
};
class Head {
    public:
        Head(std::string = "H-01", bool = true);
        ~Head();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _isFunctionnal;
};
#endif