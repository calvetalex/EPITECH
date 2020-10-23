/*
** EPITECH PROJECT, 2018
** MAIN TEST
** File description:
** MAIN TEST
*/
#include <unistd.h>
#include "include/my.h"

int main ()
{
    char buff[1000000];
    int offset = 0;
    int len;
    int buff_size;

    while ((len = read(0, buff + offset, 999999 - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    rush3(buff);
    return (0);
}
