#pragma once
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &obj);
        ~Cure();
        Cure &operator=(const Cure &obj);
        virtual AMateria* clone() const;
};