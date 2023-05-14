#include "RPN.hpp"

namespace rpn
{
    bool isOperand(int operand) {
        return (operand == addition
        || operand == subtraction
        || operand == multiplication
        || operand == division);
    }

    int retOperand(char operand) {
        if (operand == '/')
            return(division);
        if (operand == '*')
            return(multiplication);
        if (operand == '-')
            return(subtraction);
        if (operand == '+')
            return(addition);
        return(0);
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
RPN::RPN(const RPN &rhs) { (void)rhs;};
RPN::~RPN() {};
// RPN &RPN::operator=(const RPN &rhs);

bool isValidNum(const std::string &str) {
    if (rpn::isNumber(str) == false) {
        throw std::logic_error("not a number");
    } else if (str.size() > 1) {
        throw std::logic_error("too high number");
    }
    return (true);
}

int RPN::solveExperssion(const std::string &str) {
    char *token = strtok(const_cast<char *>(str.c_str()), " ");
    while (token != NULL)  {
        if (rpn::retOperand(token[0])) {
            if (m_stack.size() < 2) {
                throw std::logic_error("bad input");
            }
            int a;
            int b;
            a = m_stack.top();
            m_stack.pop();
            b = m_stack.top();
            m_stack.pop();
            int test = rpn::calculate(b, a, rpn::retOperand(token[0]));
            m_stack.push(test);
        } else if (isValidNum(token)) {
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