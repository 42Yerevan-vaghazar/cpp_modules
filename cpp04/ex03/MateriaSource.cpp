#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : m_curIndex(0) {
    for (int i = 0; i < 4; i++) {
        m_materies[i] = NULL;
    }
    std::cout << "MateriaSource default constructor called" << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource &obj) {
    int i = 0;
    m_curIndex = obj.m_curIndex;
    for (i = 0; i < 4; i++) {
        if (obj.m_materies[i]) {
            m_materies[i] = obj.m_materies[i]->clone();
        }
        else {
            break ;
        }
    }
    for (; i < 4; i++) {
        m_materies[i] = NULL;
    }
};

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete m_materies[i];
    }
    std::cout << "MateriaSource destructor called" << std::endl;
};

MateriaSource & MateriaSource::operator=(const MateriaSource &obj) {
    int i = 0;
    m_curIndex = obj.m_curIndex;
    for (i = 0; i < 4; i++) {
        if (obj.m_materies[i]) {
            m_materies[i] = obj.m_materies[i]->clone();
        }
        else {
            break ;
        }
    }
    for (; i < 4; i++) {
        m_materies[i] = NULL;
    }
    return (*this);
};

void MateriaSource::learnMateria(AMateria* materia) {
    if (m_curIndex < 4) {
        m_materies[m_curIndex++] = materia->clone();
    }
};

AMateria* MateriaSource::createMateria(std::string const & type) {
    if (type == "ice") {
        return (new Ice());
    }
    if (type == "cure") {
        return (new Cure());
    }
    return (NULL);
};
