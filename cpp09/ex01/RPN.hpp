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
    bool isOperator(int symbol);
    int retOperator(int symbol);
    int calculate(int operand1, int operand2, int symbol);
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
    private:
        void ValidNum(const std::string &str);
    private:
        std::stack<int> m_stack;
};