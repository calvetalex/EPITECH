/*
** EPITECH PROJECT, 2020
** Picture
** File description:
** Picture
*/

#include <fstream>
#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::~Picture()
{
}

Picture::Picture(const Picture &toCopy)
{
    this->data = toCopy.getData();
}

Picture::Picture(const std::string &file)
{
    std::ifstream openFile(file.c_str());
    std::string buffer;

    if (openFile.is_open()) {
        this->data.assign((std::istreambuf_iterator<char>(openFile)), (std::istreambuf_iterator<char>()));
        openFile.close();
    } else
        this->data = "ERROR";
}

Picture& Picture::operator=(const Picture &toAssign)
{
    this->data = toAssign.getData();
    return *this;
}

bool Picture::getPictureFromFile(const std::string &file)
{
     std::ifstream openFile(file.c_str());
    std::string buffer;

    if (openFile.is_open()) {
        this->data.assign((std::istreambuf_iterator<char>(openFile)), (std::istreambuf_iterator<char>()));
        openFile.close();
        return true;
    }
    this->data = "ERROR";
    return false;
}

const std::string Picture::getData(void) const
{
    return this->data;
}