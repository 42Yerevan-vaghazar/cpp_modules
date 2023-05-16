#include "RPN.hpp"

namespace rpn
{
    bool isOperand(int symbol) {
        return (symbol == addition
        || symbol == subtraction
        || symbol == multiplication
        || symbol == division);
    }

    int retOperator(int symbol) {
        if (symbol == '/')
            return(division);
        if (symbol == '*')
            return(multiplication);
        if (symbol == '-')
            return(subtraction);
        if (symbol == '+')
            return(addition);
        return(0);
    }

    int calculate(int operand1, int operand2, int symbol) {
        switch (symbol)
        {
            case addition:
                return(operand1 + operand2);
            case subtraction:
                return(operand1 - operand2);
            case multiplication:
                return(operand1 * operand2);
            case division:
                if (operand2 == 0) {
                    throw std::logic_error("division by zero");
                }
                return(operand1 / operand2);
            default:
                break;
        }
        return (0);
    }

    bool isNumber(const std::string& s)
	{
		std::string::const_iterator it = s.begin();
		while (it != s.end() && std::isdigit(*it)) {
			++it;
		}
		return (!s.empty() && it == s.end());
	}
};

RPN::RPN() {};

RPN::RPN(const RPN &rhs) { m_stack = rhs.m_stack;};

RPN::~RPN() {};

RPN &RPN::operator=(const RPN &rhs) {
    if (this != &rhs) {
        m_stack = rhs.m_stack;
    }
    return (*this);
};

void RPN::ValidNum(const std::string &str) {
    if (rpn::isNumber(str) == false) {
        throw std::logic_error("not a number");
    } else if (str.size() > 1) {
        throw std::logic_error("too high number");
    }
}

int RPN::solveExperssion(const std::string &str) {
    char *token = strtok(const_cast<char *>(str.c_str()), " ");
    while (token != NULL)  {
        if (rpn::retOperator(token[0])) {
            if (m_stack.size() < 2) {
                throw std::logic_error("bad input");
            }
            int operand1;
            int operand2;
            operand1 = m_stack.top();
            m_stack.pop();
            operand2 = m_stack.top();
            m_stack.pop();
            m_stack.push(rpn::calculate(operand2, operand1, rpn::retOperator(token[0])));
        } else {
            ValidNum(token);
            m_stack.push(std::strtol(token, NULL, 10));
        }
        token = strtok(NULL, " ");
    }
    if (m_stack.size() != 1) {
        throw std::logic_error("bad input");
    }
    int result = m_stack.top();
    m_stack.pop();
    return (result);
};