/*
** EPITECH PROJECT, 2020
** Cthulhu
** File description:
** ex00
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = strdup("Cthulhu");
    if (!this->m_name)
        return;
    this->m_power = 42;
    printf("----\nBuilding Cthulhu\n");
}

cthulhu_t *new_cthulhu(void)
{
    cthulhu_t *new_one = NULL;

    new_one = malloc(sizeof(cthulhu_t));
    if (!new_one)
        return (NULL);
    cthulhu_initializer(new_one);
    return (new_one);
}

void print_power(cthulhu_t *this)
{
    if (this)
        printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    return;
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

static void koala_initializer(koala_t *this, char *name, char legend)
{
    cthulhu_initializer(&this->m_parent);
    free(this->m_parent.m_name);
    this->m_parent.m_name = strdup(name);
    this->m_parent.m_power = (legend ? 42 : 0);
    this->m_is_a_legend = legend;
    printf("Building %s\n", name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new_one = NULL;

    new_one = malloc(sizeof(koala_t));
    if (!new_one)
        return (NULL);
    koala_initializer(new_one, name, is_a_legend);
    return (new_one);
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}