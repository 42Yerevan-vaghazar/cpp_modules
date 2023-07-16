#pragma once
#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain &obj);
        ~Brain();
        Brain &operator=(const Brain &obj);
    private:
        std::string m_ideas[100];
};