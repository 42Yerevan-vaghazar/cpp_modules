#pragma once
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string m_type;
	private:
		bool		m_isOnFloor;
	public:
 		AMateria(std::string const & type);
		virtual ~AMateria();
		std::string const & getType() const;
		void setType(std::string const & type);
		virtual AMateria* clone() const = 0;
		void take();
		void drop();
		virtual void use(ICharacter& target);
};