#pragma once
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB();
        HumanB(const std::string &name);
        ~HumanB();
        void setWeapon(Weapon &weapon);
        void attack() const;
    private:
        std::string m_name;
        Weapon *m_weapon;
};