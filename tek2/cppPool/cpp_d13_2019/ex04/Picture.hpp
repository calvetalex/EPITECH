/*
** EPITECH PROJECT, 2020
** Picture
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>

class Picture {
    public:
        Picture();
        Picture(const Picture &);
        Picture (const std::string &);
        ~Picture();
        Picture& operator=(const Picture &);
        bool getPictureFromFile(const std::string &);
        const std::string getData() const;
        void setData(const std::string&);

    public:
        std::string data;
};

#endif /* !PICTURE_HPP_ */
