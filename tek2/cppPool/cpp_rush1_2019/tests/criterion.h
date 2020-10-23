/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** struct to test
*/

#ifndef TEST_CRITERION_H_
#define TEST_CRITERION_H_

#include "criterion_object.h"
#include "criterion_container.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

typedef struct
{
    Class base;
    int value;
}IntClass;

typedef struct
{
    Class   base;
    float     value;
}FloatClass;

typedef struct
{
    Class   base;
    char   value;
}CharClass;

typedef struct
{
    Container   base;
    Class       *_type;
    size_t      _size;
    Object      **_tab;
}   ArrayClass;

typedef struct {
    Iterator    base;
    ArrayClass  *_array;
    size_t      _idx;
}   ArrayIteratorClass;

#endif /* !CRITERION_H_ */
