#pragma once
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &obj);
        virtual ~ClapTrap();
        ClapTrap& operator=(const ClapTrap &obj);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        std::string m_name;
        int         m_hit;
        int         m_energy;
        int         m_attackDamage;
};