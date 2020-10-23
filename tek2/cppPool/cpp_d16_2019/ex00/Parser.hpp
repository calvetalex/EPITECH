/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <stack>

class Parser {
    public:
        Parser();
        ~Parser();
        Parser(const Parser&);
        Parser &operator=(const Parser &);
        void feed(const std::string &);
        int result(void) const { return _res; };
        void reset(void);

        std::stack<int> getOperand(void) const { return _operand; };
        std::stack<char> getOperator(void) const { return _operator; };
    private:
        int _res;
        std::stack<char> _operator;
        std::stack<int> _operand;
};

#endif /* !PARSER_HPP_ */
