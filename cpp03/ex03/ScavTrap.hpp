#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &obj);
        virtual ~ScavTrap();
        ScavTrap& operator=(const ScavTrap &obj);
        virtual void attack(const std::string& target);
        void guardGate();
};