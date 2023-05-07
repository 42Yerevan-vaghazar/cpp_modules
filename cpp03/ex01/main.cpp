#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap *ptr;
	ScavTrap a("barev");
	// ScavTrap b = a;
	ScavTrap b = a;
	b = a;
	ClapTrap c("barev");
	ptr = &a;
	c.attack("poxos");
	c.takeDamage(11);
	b.attack("ba");
	b.takeDamage(11);
	a.guardGate();
	ptr->attack("poxos");
	return 0;
}