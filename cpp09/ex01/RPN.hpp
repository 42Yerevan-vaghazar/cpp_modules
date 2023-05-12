#pragma once
#include <stack>
#include <iostream>
#include <utility>


enum
{
    addition,
    subtraction,
    multiplication,
    division
};

class RPN
{
    public:
        RPN();
        RPN(const RPN &rhs);
        ~RPN();
        RPN &operator=(const RPN &rhs);
        void addExpression(unsigned short parameter, short operand);
        int calculateExpression(int last);
    private:
        std::stack<std::pair<int, char> > m_stack;
};