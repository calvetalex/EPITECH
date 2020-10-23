/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "MyGKrellm.hpp"
#include "Parser.hpp"

static void printHelp(void)
{
    std::cout << "Usage : ./MyGKrellm <Flag> <ConfigFile>" << std::endl;
    std::cout << "\t-h || --help : Print Usage" << std::endl;
    std::cout << "\t-gui || --graphical : Open the program with a nice Graphical User Interface" << std::endl;
    std::cout << "\t-tui || --textual : Open the program with a nice Textual User Interface" << std::endl;
    exit(-1);
}

static void printError(const std::string &message)
{
    std::cerr << message << std::endl << std::endl;
    printHelp();
}

int main(int argc, char **argv, char **env)
{
    Parser config;

    if (env == nullptr)
        printError("Environnement is null, please check your environnement");
    if (argc < 3 || std::strcmp(argv[1], "-h") == 0 || std::strcmp(argv[1], "--help") == 0)
        printHelp();
    if (std::strcmp(argv[1], "-gui") == 0 || std::strcmp(argv[1], "--graphical") == 0) {
        config.parseConfigFile(argv[2]);
        runSFML(config.getOptions());
    } else if (std::strcmp(argv[1], "-tui") == 0 || std::strcmp(argv[1], "--textual") == 0) {
        config.parseConfigFile(argv[2]);
        runNcurse(config.getOptions());
    } else {
        printError("Entered flag is not a recognised flag");
    }
    return (0);
}
