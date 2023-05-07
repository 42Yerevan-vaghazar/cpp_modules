#pragma once
#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void announce(void);
		void setName(const std::string &name);
	private:
		std::string	m_name;
};