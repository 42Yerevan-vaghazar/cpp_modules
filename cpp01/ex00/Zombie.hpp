#pragma once
#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void announce(void);
	private:
		std::string	m_name;
};