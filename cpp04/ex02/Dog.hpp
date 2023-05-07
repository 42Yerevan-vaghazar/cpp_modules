#pragma once
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const std::string &name);
        Dog(const Dog &obj);
        virtual ~Dog();
        Dog &operator=(const Dog &obj);
        virtual void makeSound() const;
    private:
        Brain* m_brain;
};