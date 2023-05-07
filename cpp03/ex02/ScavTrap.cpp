#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    ClapTrap::m_hit = 100;
    ClapTrap::m_energy = 50;
    ClapTrap::m_attackDamage = 20;
};

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    ClapTrap::m_hit = 100;
    ClapTrap::m_energy = 50;
    ClapTrap::m_attackDamage = 20;
    std::cout << "ScavTrap parametr constructor called" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = obj;
};

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap &obj) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    ClapTrap::operator=(obj);
    return (*this);
};

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
};

void ScavTrap::attack(const std::string& target) {
    if (m_energy > 0 && m_hit > 0) {
        std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing "\
        << m_attackDamage << " points of damage!" << std::endl;
        m_energy--;
    }
    else if (m_energy <= 0)
        std::cout << "ScavTrap " << m_name << "has died." << std::endl;
    else
        std::cout << "ScavTrap " << m_name << "need being Repaired." << std::endl;
};