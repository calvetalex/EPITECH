/*
** EPITECH PROJECT, 2020
** cpp_rus3_2019
** File description:
** Parser to get config class
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include <list>
    #include <string>

    class Parser {
        public:
            Parser();
            Parser(const Parser &);
            ~Parser();
            Parser &operator=(const Parser&);

            void parseConfigFile(const std::string&);
            void createMap(void);

            std::list<std::string> getOptions(void) const;
        private:
            std::list<std::string> _options;
    };

#endif /* !PARSER_HPP_ */
