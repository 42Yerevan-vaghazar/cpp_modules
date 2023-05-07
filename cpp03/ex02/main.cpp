#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <fcntl.h>
#include <locale>

int main( void ) {
	ClapTrap *ptr;
	FragTrap a("barev");
	FragTrap b = a;
	ScavTrap g;
	// std::cout << b.m_name << std::endl;
	// std::cout << b.m_attackDamage << std::endl;
	// ClapTrap b(a);
	// ClapTrap& m = b;
	ClapTrap c;
	// FragTrap g("poxos");
	// ClapTrap t;
	// b = m;
	// std::cout << a << 
	// ClapTrap c("barev");
	ptr = &a;
	c.attack("poxos");
	g.attack("poxos");
	c.takeDamage(11);
	b.attack("ba");
	b.takeDamage(13);
	ptr->attack("dfasdf");
	a.highFivesGuys();
	return 0;
}