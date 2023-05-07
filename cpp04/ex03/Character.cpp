#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() {
	m_name = "default";
	for (int i = 0; i < 4 ; i++) {
		m_materias[i] = NULL;
	}
	slotIndex = 0;
	m_dropedCount = 0;
	for (int i = 0; i < 10; i++) {
		m_dropedMaterias[i] = NULL;
	}
};

Character::Character(const std::string &name) {
	m_name = name;
	slotIndex = 0;
	for (int i = 0; i < 4 ; i++) {
		m_materias[i] = NULL;
	}
	m_dropedCount = 0;
	for (int i = 0; i < 10; i++) {
		m_dropedMaterias[i] = NULL;
	}
}

Character::Character(const Character &obj) {
	m_name = obj.m_name;
	int i = 0;
	for (i = 0; i < 4 ; i++) {
		if (obj.m_materias[i]) {
			m_materias[i] = obj.m_materias[i]->clone();
		}
		else {
			break ;
		}
	}
	slotIndex = i;
	for (; i < 4 ; i++) {
		m_materias[i] = NULL;
	}
	m_dropedCount = 0;
	for (int i = 0; i < 10; i++) {
		m_dropedMaterias[i] = NULL;
	}
};

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete m_materias[i];
	}
	for (int i = 0; i < 10; i++) {
		delete m_dropedMaterias[i];
	}
};

Character &Character::operator=(const Character &obj) {
	if (this != &obj) {
		m_name = obj.m_name;
		for (int i = 0; i < 4 ; i++) {
			delete m_materias[i];
		}
		for (int i = 0; i < 10; i++) {
			delete m_dropedMaterias[i];
		}
		int i = 0;
		for (i = 0; i < 4 ; i++) {
			if (obj.m_materias[i]) {
				m_materias[i] = obj.m_materias[i]->clone();
			}
			else {
				break ;
			}
		}
		slotIndex = i;
		for (; i < 4 ; i++) {
			m_materias[i] = NULL;
		}
	}
	return (*this);
};

std::string const & Character::getName() const {
	return (m_name);
};

void Character::equip(AMateria* m) {
	if (slotIndex < 4 && m) {
		m->take();
		m_materias[slotIndex++] = m;
	}
};

void Character::unequip(int idx) {
	if (idx < 4 && idx >= 0 && m_materias[idx] != NULL) {
		m_dropedMaterias[m_dropedCount++] = m_materias[idx];
		m_materias[idx]->drop();
		m_materias[idx] = NULL;
	}
};

void Character::use(int idx, ICharacter& target) {
	if (idx < 4 && idx >= 0 && m_materias[idx] != NULL) {
		m_materias[idx]->use(target);
	}
};