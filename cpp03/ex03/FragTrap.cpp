#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    m_hit = 100;
    m_energy = 100;
    m_attackDamage = 30;
};

FragTrap::FragTrap(const std::string &name) {
    m_name = name;
    m_hit = 100;
    m_energy = 100;
    m_attackDamage = 30;
    std::cout << "FragTrap parametr constructor called" << std::endl;
};


FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = obj;
};

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap &obj) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    ClapTrap::operator=(obj);
    return (*this);
};

void FragTrap::highFivesGuys() {
    std::cout << " let's high five" << std::endl;
};

void FragTrap::attack(const std::string& target) {
    if (m_energy > 0 && m_hit > 0) {
        std::cout << "FragTrap " << m_name << " attacks " << target << ", causing "\
        << m_attackDamage << " points of damage!" << std::endl;
        m_energy--;
    }
    else if (m_energy <= 0)
        std::cout << "FragTrap " << m_name << "has died." << std::endl;
    else
        std::cout << "FragTrap " << m_name << "need being Repaired." << std::endl;
};