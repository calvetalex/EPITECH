/*
** EPITECH PROJECT, 2020
** Santa
** File description:
** Xml
*/

#ifndef XML_HPP
    #define XML_HPP

    #include <string>
    #include <regex>

    #include "Regexes.hpp"
    #include "Object/Wrap/GiftPaper.hpp"

    class Xml {
        public:
            Xml(const std::string &giftTemplate = "template.xml");
            ~Xml();
            std::string serialize(const std::string &type,
                                    const std::string &title);
            void unserialize(const std::string &fileName);


        protected:
        private:
            std::string giftTemplate;
            void writeSerializedToFile(const std::string &serialized);
            bool checkValidity(std::ifstream &filename, std::string &content,
                                std::smatch &matches);
    };

#endif /* !XML_HPP */
