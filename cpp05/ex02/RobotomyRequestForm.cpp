#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest", 145, 137) {
    m_target = target;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) {
    m_target = obj.m_target;
};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj) {
        m_target = obj.m_target;
    }
    return (*this);
};

void RobotomyRequestForm::action() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Dzzzzzzzzzzzz" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::srand(time(NULL));
    int randNum = std::rand() % 2;
    switch(randNum) {
        case 0 :
            std::cout << m_target << " has been robotomized successfully 50% of the time" << std::endl;
            break ;
        default:
            std::cout << m_target << "'s robotomy failed" << std::endl;
    }
};