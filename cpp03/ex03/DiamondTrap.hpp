#pragma once
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap &obj);
        virtual ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &obj);
        virtual void attack(const std::string& target);
        void whoAmI();
    private:
        std::string m_name;
};
