/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** Xml
*/

#include "Xml/Xml.hpp"
#include <iostream>
#include <fstream>
#include <regex>
#include "Object/Wrap/GiftPaper.hpp"

Xml::Xml(const std::string &giftTemplate)
{
    this->giftTemplate = giftTemplate;
}

Xml::~Xml()
{
}

std::string Xml::serialize(const std::string &type, const std::string &title)
{
    std::ifstream templateStream(giftTemplate);
    std::string serialized((std::istreambuf_iterator<char>(templateStream)),
                             std::istreambuf_iterator<char>());

    serialized = std::regex_replace(serialized,
                                    std::regex(r_typeTemplate),
                                    type);
    serialized = std::regex_replace(serialized,
                                    std::regex(r_titleTemplate),
                                    title);
    serialized = std::regex_replace(serialized,
                                    std::regex(r_packedTemplate),
                                    "true");
    serialized = std::regex_replace(serialized,
                                    std::regex(r_wrappedTemplate),
                                    "true");
    return serialized;
}

void Xml::writeSerializedToFile(const std::string &serialized)
{
    int i = 0;
    std::ofstream file;
    for (file.open(std::string("gift" + std::to_string(i) + ".xml"));
            file.good(); i++)
            file.close();
    file << serialized;
    file.close();
}


void Xml::unserialize(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string content;
    std::smatch matches;
    std::string title;
    std::string type;

    if (!(file.good()))
        return;
    content = std::string(std::istreambuf_iterator<char>(file),
                        std::istreambuf_iterator<char>());
    if (!checkValidity(file, content, matches))
        return;
    std::regex_search(content, matches, std::regex(r_title));
    title = matches.str(1);
    std::regex_search(content, matches, std::regex(r_type));
    type = matches.str(1);
}

bool Xml::checkValidity(std::ifstream &filename,
                        std::string &content, std::smatch &matches)
{
    if (!(std::regex_search(content, std::regex(r_overallSyntax))))
        return false;
    std::regex_search(content, matches, std::regex(r_header));
    if (matches.size() != 2)
        return false;
    std::regex_search(content, matches, std::regex(r_title));
    if (matches.size() != 2)
        return false;
    std::regex_search(content, matches, std::regex(r_type));
    if (matches.size() != 2 || (matches.str(1).c_str() != "TEDDY"
        && matches.str(1).c_str() != "PONY"))
        return false;
    std::regex_search(content, matches, std::regex(r_packed));
    if (matches.size() != 2 || (matches.str(1).c_str() != "true"
        && matches.str(1).c_str() != "false"))
        return false;
    std::regex_search(content, matches, std::regex(r_wrapped));
    if (matches.size() != 2 || (matches.str(1).c_str() != "true"
        && matches.str(1).c_str() != "false"))
        return false;
    return true;
}
