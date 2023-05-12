#include "RPN.hpp"

namespace rpn
{
    bool isOperand(int operand) {
        return (operand == addition
        || operand == subtraction
        || operand == multiplication
        || operand == division);
    }

    int calculate(int a, int b, int operand) {
        switch (operand)
        {
            case addition:
                return(a + b);
            case subtraction:
                return(a - b);
            case multiplication:
                return(a * b);
            case division:
                return(a / b);
            default:
                break;
        }
        return (0);
    }
};

RPN::RPN() {};
RPN::RPN(const RPN &rhs) { (void)rhs;};
RPN::~RPN() {};
// RPN &RPN::operator=(const RPN &rhs);

void RPN::addExpression(unsigned short parameter, short operand) {
    if (rpn::isOperand(operand) == false) {
        throw std::logic_error("bad operator");
    }
    if (parameter > 10) {
        throw std::logic_error("bad parameter");
    }
    m_stack.push(std::make_pair(parameter, operand));
};

int RPN::calculateExpression(int last) {
    int result = last;
    std::pair<int, char> pair;
    while (m_stack.empty() == false) {
        pair = m_stack.top();
        result = rpn::calculate(result, pair.first, pair.second);
        m_stack.pop();
    }
    return (result);
};
