/*
** EPITECH PROJECT, 2020
** GiftPaper
** File description:
** GiftPaper
*/

#include "Object/Wrap/GiftPaper.hpp"

GiftPaper::GiftPaper(Type type)
{
    this->_typeObj = type;
}

GiftPaper::GiftPaper(GiftPaper &cpy) : AWrap()
{
    this->_typeObj = cpy._typeObj;
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::wrapMeThat(AObject *obj)
{
    this->_boxWraped = (Box*)obj;
}

AObject *GiftPaper::takeOff(void) const
{
    return (AObject*)this->_boxWraped;
}