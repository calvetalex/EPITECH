/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** menger.c
*/


#ifndef MENGER_H_
    #define MENGER_H_

#include <stdint.h>

    typedef struct menger_s {
        int x;
        int y;
        int size;
        int level;
    } menger_t;


void menger(menger_t data, unsigned int **img);

#endif