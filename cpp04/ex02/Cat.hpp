#pragma once
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const std::string &name);
        Cat(const Cat &obj);
        ~Cat();
        Cat &operator=(const Cat &obj);
        virtual void makeSound() const;
    private:
        Brain* m_brain;
};