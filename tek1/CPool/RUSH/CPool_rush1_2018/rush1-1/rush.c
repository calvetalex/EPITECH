/*
** EPITECH PROJECT, 2018
** rush.c
** File description:
** display a square composed by '°' & '-' & '|'
*/

int disp_ang(int x, int y, int line, int colon)
{
    if ( line == 1 || line == y) {
        if (colon == 1 || colon == x) {
            my_putchar('o');
            return (0);
        }
    }
    return (1);
}

int disp_side(int x, int y, int line, int colon)
{
    if (line == 1 || line == y) {
        if (colon > 1 && colon < x) {
            my_putchar('-');
            return (0);
        }
    }
    if (colon == 1 || colon == x ) {
        if (line > 1 && line < y ) {
            my_putchar('|');
            return (0);
        }
    }
    return (1);
}

void disp_content(int angle, int side)
{
    if (angle == 1 && side == 1)
        my_putchar(' ');
}

void rush(int x, int y)
{
    int line = 1;
    int colon = 1;
    int angle;
    int side;
    int limit = 2147483647;

    if (x <= 0 || y <= 0 || x >= limit || y >= limit)
        write(2, "Invalid size\n", 14);
    else {
        for(line = 1; line <= y; line++) {
            for(colon = 1; colon <= x; colon++) {
                angle = disp_ang(x, y, line, colon);
                side = disp_side(x, y, line, colon);
                disp_content(angle, side);   
            }
            my_putchar('\n');
        }
    }
}
