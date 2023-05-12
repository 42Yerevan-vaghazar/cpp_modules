#include <stack>
#include <iostream>
#include <utility>
#include "RPN.hpp"

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    RPN rpn;
    rpn.addExpression(2, multiplication);
    rpn.addExpression(2, multiplication);
    rpn.addExpression(1, subtraction);
    rpn.addExpression(1, subtraction);
    std::cout << rpn.calculateExpression(5) << std::endl;

}