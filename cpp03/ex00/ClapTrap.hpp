#pragma once
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &obj);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap &obj);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    private:
        std::string m_name;
        int         m_hit;
        int         m_energy;
        int         m_attackDamage;
};