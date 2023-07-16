#include "Bureaucrat.hpp"

int main() {
    // try
    // {
    //     Bureaucrat a("bob", 151);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // Bureaucrat a("bob", 150);
    // try
    // {
    //     a.decrement();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    try
    {
        Bureaucrat a("bob", 1);
        a.increment();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    // std::cout << a << std::endl;
}