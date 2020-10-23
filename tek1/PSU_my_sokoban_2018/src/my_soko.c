/*
** EPITECH PROJECT, 2018
** my_popup.c
** File description:
** disp a str in the middle of the terminal
*/

#include <curses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int direction(int ch, char *str)
{
    switch (ch) {
    case KEY_RIGHT:
        move_right(str);
        break;
    case KEY_LEFT:
        move_left(str);
        break;
    case KEY_UP:
        move_up(str);
        break;
    case KEY_DOWN:
        move_down(str);
        break;
    default:
        return (-1);
    }
    mvprintw(0, 0, str);
    refresh();
    return (0);
}

int my_popup(char *str, char *map)
{
    int ch;
    char *save;

    initscr();
    keypad(stdscr, TRUE);
    mvprintw(0, 0, str);
    noecho();
    curs_set(0);
    while (ch != 'q') {
        ch = getch();
        if (ch == ' ') {
            str = map;
            save = str;
            my_popup(str, save);
        }
        direction(ch, str);
    }
    endwin();
    return (0);
}

char *have_map(char *str, char *map)
{
    struct stat *buff;
    int mapsize = 0;
    int fd = 0;
    int retread = 0;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (ERROR);
    buff = malloc(sizeof(struct stat));
    stat(str, buff);
    mapsize = buff->st_size;
    map = malloc(sizeof(char) * mapsize);
    if (map == NULL)
        return (ERROR);
    retread = read(fd, map, mapsize);
    if (retread == -1)
        return (ERROR);
    return (map);
}

int test_map(char *str)
{
    int target = 0;
    int boxes = 0;
    int player = 0;

    while (*str != '\0'){
        if (*str == 'O')
            target++;
        if (*str == 'X')
            boxes++;
        if (*str == 'P')
            player++;
        str++;
    }
    if (player == 0 || player > 1)
        exit (84);
    if (target < boxes)
        exit (84);
    if (boxes == 0)
        exit (84);
}

int main(int ac, char **av)
{
    char *map;
    char *save;

    if (ac < 2) {
        write(0,"my_sokoban: error 1: 0 argv given but 1 required\n", 49);
        return (84);
    }
    if (av[1][0] == '-')
        if (av[1][1] == 'h'){
            disp_use();
            return (0);
        }
    map = have_map(av[1], map);
    save = have_map(av[1], map);
    if (map == ERROR)
        return (84);
    test_map(map);
    my_popup(map, save);
}
