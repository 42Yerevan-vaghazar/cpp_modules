#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery creation", 145, 137) {
    std::cout << __func__ << " called" << std::endl;
    m_target = target;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) :  AForm(obj) {
    m_target = obj.m_target;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << __func__ << " called" << std::endl;
};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this != &obj) {
        AForm::operator=(obj);
        m_target = obj.m_target;
    }
    return (*this);
};

void ShrubberyCreationForm::action() const {
    std::ofstream ofs((m_target + "_shrubbery"), std::ofstream::out);
    std::string str = "barev";
    if (ofs.is_open()) {
        ofs << "          1          " << std::endl;
        ofs << "         / \\         " << std::endl;
        ofs << "        /   \\        " << std::endl;
        ofs << "       /     \\       " << std::endl;
        ofs << "      2       3      " << std::endl;
        ofs << "     / \\     / \\     " << std::endl;
        ofs << "    4   5   6   7    " << std::endl;
        ofs << "   /   / \\     / \\   " << std::endl;
        ofs << "  8   9   1   2   3  " << std::endl;
        ofs << "     /               " << std::endl;
        ofs << "    4                " << std::endl;
        if (ofs.good() == false) {
            std::cerr << "something went wrong" << std::endl;
        }
        ofs.close();
    } else {
        std::cerr << "Error opening file" << std::endl;
    }
};