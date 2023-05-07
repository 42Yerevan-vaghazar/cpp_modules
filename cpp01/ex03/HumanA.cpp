#include "HumanA.hpp"

// HumanA::HumanA() {};

HumanA::~HumanA() {};

HumanA::HumanA(const std::string &name, Weapon &weapon) : m_weapon(weapon){
	m_name = name;
};

void HumanA::attack() const {
	std::cout << m_name << " attacks with their " << m_weapon.getType()
	<< std::endl;
};