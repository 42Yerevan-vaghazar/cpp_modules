#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <fcntl.h>
#include <locale>

int main( void ) {
	DiamondTrap c("barev");
	c.whoAmI();
	c.attack("poxos");
	c.takeDamage(11);
	c.beRepaired(120);
	c.guardGate();
	c.highFivesGuys();
	return 0;
}