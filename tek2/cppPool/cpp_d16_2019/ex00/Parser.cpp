/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** Parser
*/

#include <iostream>
#include "Parser.hpp"
/* --- CALC ---- */
static int add(int a, int b) {
    return a + b;
}

static int minus(int a, int b) {
    return a - b;
}

static int mul(int a, int b) {
    return a * b;
}

static int divide(int a, int b) {
    return a / b;
}

static int mod(int a, int b) {
    return a % b;
}

/* ----- Do operation ---- */

static int doOp(char op, int a, int b) {
    switch (op)
    {
    case '+':
        return add(b, a);
    case '-':
        return minus(b, a);
    case '*':
        return mul(b, a);
    case '/':
        return divide(b, a);
    case '%':
        return mod(b, a);
    default:
        break;
    }
    return 0;
}

/* ---- Parser Method ---- */

Parser::Parser()
{
    this->_res = 0;
}

Parser::~Parser()
{
}

Parser::Parser(const Parser&toCopy)
{
    this->_res = toCopy.result();
    this->_operand = toCopy.getOperand();
    this->_operator = toCopy.getOperator();
}

Parser &Parser::operator=(const Parser&toAssign)
{
    this->_res = toAssign.result();
    this->_operand = toAssign.getOperand();
    this->_operator = toAssign.getOperator();
    return *this;
}

void Parser::feed(const std::string &calc) {
    std::string tmp;
    int nb1 = 0;
    int nb2 = 0;

    for (int i = 0; calc[i] != '\0'; i++) {
        tmp.clear();
        nb1 = 0;
        nb2 = 0;
        if (calc[i] >= '0' && calc[i] <= '9') {
                for (; calc[i] >= '0' && calc[i] <= '9'; i++) {
                    tmp += calc[i];
                }
                this->_operand.push(std::stoi(tmp));
        }
        if (calc[i] == '*' || calc[i] == '/' || calc[i] == '%' || calc[i] == '+' || calc[i] == '-' || calc[i] == '(') {
            this->_operator.push(calc[i]);
        }
        if (calc[i] == ')') {
            while (this->_operator.top() != '(') {
                nb1 = this->_operand.top();
                this->_operand.pop();
                nb2 = this->_operand.top();
                this->_operand.pop();
                this->_operand.push(doOp(this->_operator.top(), nb1, nb2));
                this->_operator.pop();
            }
            this->_operator.pop();
        }
    }
    while (!this->_operator.empty()) {
        nb1 = this->_operand.top();
        this->_operand.pop();
        nb2 = this->_operand.top();
        this->_operand.pop();
        this->_operand.push(doOp(this->_operator.top(), nb1, nb2));
        this->_operator.pop();
    }
    this->_res += this->_operand.top();
    this->_operand.pop();
}

void Parser::reset(void)
{
    while(!this->_operator.empty())
        this->_operator.pop();
    while(!this->_operand.empty())
        this->_operand.pop();
    this->_res = 0;
}