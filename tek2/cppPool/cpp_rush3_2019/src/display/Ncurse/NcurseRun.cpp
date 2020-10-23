/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Ncurse run function
*/

//! \date 01 February 2020
//! \version
//! \author Alexandre Calvet

//! \file NcurseRun.cpp
//! \brief Main loop function for Ncurse display

#include <ncurses.h>
#include <thread>
#include <chrono>
#include "display/NcurseMonitor.hpp"

//! \fn void customSleep(int)
//! \brief Sleep for a given time

//! \param[in] Int : Given time to sleep
//! \param[out] void
//! \return Sleep function don't return anything
static void customSleep(uint16_t x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void getHeader(WINDOW *stdscr)
{
     WINDOW *subWinHeader = newwin(3, getmaxx(stdscr), 0, 0);

    box(subWinHeader, 0, 0);
    refresh();
    mvwprintw(subWinHeader, 1, 2, "MyGKrellm: Graphical Task Monitor");
    mvwprintw(subWinHeader, 1, getmaxx(stdscr) - 25, "to exit press 'Ctrl-C'");
    wrefresh(subWinHeader);
}

int runNcurse(std::list<std::string> moduleList)
{
    NcurseMonitor monitor(moduleList);

    initscr();
    keypad(stdscr, TRUE);
    monitor.setMaxX(getmaxx(stdscr));
    monitor.setMaxY(getmaxy(stdscr));
    noecho();
    refresh();
    curs_set(0);
    while (1) {
        monitor.updateModules();
        clear();
        getHeader(stdscr);
        monitor.displayModule();
        customSleep(1000);
    }
    endwin();
    return 0;
}