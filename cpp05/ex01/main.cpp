#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        Bureaucrat a("bob", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat a("bob", 150);
        a.decrement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    Form b("form", 1, 5);
    try
    {
        Bureaucrat a("bob", 5);
        Form form("Babken", 15, 20);
        std::cout << form << std::endl;
        a.signForm(form);
        a.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << b << std::endl;
}