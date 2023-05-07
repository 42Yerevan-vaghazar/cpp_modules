#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria constructor called" << std::endl;
    this->m_type = type;
    m_isOnFloor = true;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

void AMateria::setType(std::string const & type) {
    m_type = type;
};

std::string const &AMateria::getType() const {
    return (m_type);
};

void AMateria::use(ICharacter& target) {
    if (m_type == "ice") {
        std::cout << "* shoots an ice bolt at " << target.getName() << " *"  << std::endl;
    }
    if (m_type == "cure") {
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    }
};

void AMateria::take() {
    m_isOnFloor = false;
};

void AMateria::drop() {
    m_isOnFloor = true;
};