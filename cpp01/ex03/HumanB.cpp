#include "HumanB.hpp"

HumanB::HumanB() {};

HumanB::HumanB(const std::string &name) {
    m_name = name;
};

HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon &weapon) {
    m_weapon = &weapon;
};

void HumanB::attack() const {
	std::cout << m_name << " attacks with their ";
    if (m_weapon)
        std::cout << m_weapon->getType() << std::endl;
    else
        std::cout << "hands" << std::endl;
};