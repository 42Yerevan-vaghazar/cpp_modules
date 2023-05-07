#pragma once
#include "Weapon.hpp"

class HumanA
{
    public:
        // HumanA();
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA();
        void attack() const;
    private:
        std::string m_name;
        Weapon &m_weapon;
};