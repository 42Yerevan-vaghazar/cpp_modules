#pragma once
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		virtual ~MateriaSource();
		MateriaSource &operator=(const MateriaSource &obj);
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
	private:
		AMateria	*m_materies[4];
		int         m_curIndex;
};