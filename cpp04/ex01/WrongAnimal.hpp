#pragma once
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const std::string &name);
        WrongAnimal(const WrongAnimal &obj);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &obj);
        void makeSound() const;
    protected:
        std::string m_type;
};