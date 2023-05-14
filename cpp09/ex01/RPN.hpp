#pragma once
#include <stack>
#include <iostream>
#include <utility>


enum
{
    addition = 1,
    subtraction,
    multiplication,
    division
};

namespace rpn
{
    typedef std::pair<int, char> pair;
    bool isOperand(int operand);
    int retOperand(char operand);
    int calculate(int a, int b, int operand);
    bool isNumber(const std::string& s);
};

class RPN
{
    public:
        RPN();
        RPN(const RPN &rhs);
        ~RPN();
        RPN &operator=(const RPN &rhs);
        int solveExperssion(const std::string &str);
        // void addExpression(unsigned short parameter, short operand);
        // int calculateExpression(int last);
    private:
        std::stack<int> m_stack;
};