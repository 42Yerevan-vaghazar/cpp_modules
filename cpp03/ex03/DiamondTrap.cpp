#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"


DiamondTrap::DiamondTrap() {
    m_name = "default_name";
    m_hit = FragTrap::m_hit;
    m_energy = ScavTrap::m_energy;
    m_attackDamage = FragTrap::m_attackDamage;
    m_name = ClapTrap::m_name + "_clap_name";
    std::cout << "DiamondTrap default constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(const std::string name) {
    m_name = name;
    m_hit = FragTrap::m_hit;
    m_energy = ScavTrap::m_energy;
    m_attackDamage = FragTrap::m_attackDamage;
    m_name = ClapTrap::m_name + "_clap_name";
    std::cout << "DiamondTrap parametr constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &obj) {
    m_name = obj.m_name;
    m_hit = FragTrap::m_hit;
    m_energy = ScavTrap::m_energy;
    m_attackDamage = FragTrap::m_attackDamage;
    m_name = obj.m_name + "_clap_name";
    std::cout << "DiamondTrap copy constructor called" << std::endl;
};

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
};

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
    m_name = obj.m_name;
    m_hit = obj.m_hit;
    m_energy = obj.m_energy;
    m_attackDamage = obj.m_attackDamage;
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    return (*this);
};

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target); // TODO It attacks causing damage of ScavTrap insteed of FragTrap
};

void DiamondTrap::whoAmI() {
    std::cout << m_name << std::endl;
    std::cout << ClapTrap::m_name << std::endl;
};