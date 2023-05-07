#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a("barev");
	// ScavTrap b = a;
	ClapTrap b = a;
	b = a;
	ClapTrap c("barev");
	c.attack("poxos");
	c.takeDamage(9);
	b.attack("ba");
	b.takeDamage(9);
	return 0;
}