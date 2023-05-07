#include "Zombie.hpp"


Zombie::Zombie() : m_name("default name") {
    std::cout << __func__ << " default ctor called" << std::endl;
};

Zombie::~Zombie() {
    std::cout << __func__ << " dctor called" << std::endl;
};

Zombie::Zombie(std::string name) : m_name(name) {
    std::cout << __func__ << " parameter ctor called" << std::endl;
};

void Zombie::announce(void) {
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};