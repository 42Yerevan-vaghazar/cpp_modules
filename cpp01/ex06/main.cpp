#include "Harl.hpp"

int main(int ac, char **av) {
    Harl harl;
    (void)ac;
    switch (ac)
    {
        case 2:
            harl.complain(std::string(av[1]));
            break;
        default:
            std::cerr << "Error: wrong number of arguments" << std::endl;
            break;
    }
}