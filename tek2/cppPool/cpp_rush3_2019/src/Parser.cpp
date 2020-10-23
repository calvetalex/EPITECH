/*
** EPITECH PROJECT, 2020
** cpp_rus3_2019
** File description:
** Parser to get config from file
*/

#include <fstream>
#include "Parser.hpp"


/*
** --------------
** ---- TOOL ----
** --------------
*/
static void lowercase(std::string& s)
{
    for (size_t i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
}

/*
** --------------
** -  CANONIC F -
** --------------
*/

Parser::Parser()
{
}

Parser::Parser(const Parser&toCopy)
{
    this->_options = toCopy.getOptions();
}

Parser::~Parser()
{
    while (!this->_options.empty())
        this->_options.pop_front();
}

Parser& Parser::operator=(const Parser&toAssign)
{
    this->_options = toAssign.getOptions();
    return *this;
}

/*
** --------------
** --- Getter ---
** --------------
*/

std::list<std::string> Parser::getOptions(void) const
{
    return this->_options;
}

/*
** --------------
** ---- Algo ----
** --------------
*/

void Parser::parseConfigFile(const std::string &filename)
{
    std::ifstream configFile(filename);
    std::string moduleName;
    std::string delimiter = "=";
    size_t pos = 0;

    if (!configFile.is_open())
        return;
    for (std::string line; getline(configFile, line);) {
        pos = line.find(delimiter);
        if (pos != std::string::npos) {
            moduleName = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            lowercase(line);
            if (line == "true")
                this->_options.push_back(moduleName);
        }
    }
}