#pragma once
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &obj);
        virtual ~Ice();
        Ice &operator=(const Ice &obj);
        virtual AMateria* clone() const;
};

