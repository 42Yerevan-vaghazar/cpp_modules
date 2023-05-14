#include <stack>
#include <iostream>
#include <utility>
#include "RPN.hpp"

std::stack<rpn::pair> parseExpresion(char *str) {
    std::stack<rpn::pair> tokens;
    char operand = 0;
    int param = 0;
    char *token = strtok(str, " ");
    tokens.push(std::make_pair(std::strtol(token, NULL, 10), 0));
    token = strtok(NULL, " ");
    while (token != NULL) {
        param = std::strtol(token, NULL, 10);
        token = strtok(NULL, " ");
        if (token && token[0] && token[1] == '\0') {
            operand = rpn::retOperand(token[0]);
        }
        tokens.push(std::make_pair(param, operand));
        token = strtok(NULL, " ");
    }
    return (tokens);
}

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    if (ac == 2) {
        try
        {
            RPN rpn;
            std::cout << rpn.solveExperssion(av[1]) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    } else {
        std::cout << "Usage" << std::endl;
    }
}
