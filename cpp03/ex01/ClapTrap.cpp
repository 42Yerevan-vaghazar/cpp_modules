#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
        : m_name("default_name"), m_hit(10),
        m_energy(10), m_attackDamage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
};

ClapTrap::ClapTrap(const std::string &name)
        : m_name(name), m_hit(10),
        m_energy(10), m_attackDamage(0)  {
    std::cout << "ClapTrap parametr constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &obj) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    m_name = obj.m_name;
    m_attackDamage = obj.m_attackDamage;
    m_hit = obj.m_hit;
    m_energy = obj.m_energy;
};

ClapTrap& ClapTrap:: operator=(const ClapTrap &obj) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    m_name = obj.m_name;
    m_attackDamage = obj.m_attackDamage;
    m_hit = obj.m_hit;
    m_energy = obj.m_energy;
    return (*this);
};

void ClapTrap::attack(const std::string& target) {
    if (m_energy > 0 && m_hit > 0) {
        std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing "\
        << m_attackDamage << " points of damage!" << std::endl;
        m_energy--;
    }
    else if (m_energy <= 0)
        std::cout << "ClapTrap " << m_name << "has died." << std::endl;
    else
        std::cout << "ClapTrap " << m_name << "need being Repaired." << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount) {
    if (m_energy > 0 && m_hit > 0) {
        std::cout << "ClapTrap " << m_name << " lost " << amount << " amount of hit point." << std::endl;
        m_hit -= amount;
    }
    else if (m_energy <= 0)
        std::cout << "ClapTrap " << m_name << "has died" << std::endl;
    else
        std::cout << "ClapTrap " << m_name << "need being Repaired." << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount) {
    if (m_energy > 0 && m_hit > 0) {
        std::cout << "ClapTrap " << m_name << "has got " << amount << "amount of hit point." << std::endl;
        m_hit += amount;
        m_energy--;
    }
    else if (m_energy <= 0)
        std::cout << "ClapTrap " << m_name << "has died." << std::endl;
};

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
};