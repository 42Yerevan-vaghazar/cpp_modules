#pragma once
#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const std::string &name);
        Animal(const Animal &obj);
        virtual ~Animal();
        Animal &operator=(const Animal &obj);
        virtual void makeSound() const;
    protected:
        std::string m_type;
};