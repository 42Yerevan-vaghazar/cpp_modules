#include <stack>
#include <iostream>
#include <utility>
#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac == 2) {
        try
        {
            RPN rpn;
            std::cout << rpn.solveExperssion(av[1]) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << '\n';
        }
    } else {
        std::cout << "Usage: ./RPN [operand] [operand] [operator]" << std::endl;
    }
}
