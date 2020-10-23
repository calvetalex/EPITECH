/*
** EPITECH PROJECT, 2020
** FIND
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename T>
typename T::iterator do_find(T& obj, int nb)
{
    return std::find(obj.begin(), obj.end(), nb);
}


#endif /* !FIND_HPP_ */
