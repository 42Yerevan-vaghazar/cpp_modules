#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &obj);
        virtual ~FragTrap();
        FragTrap& operator=(const FragTrap &obj);
        virtual void attack(const std::string& target);
        void highFivesGuys(void);
};