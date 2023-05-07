#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	Zombie zombie;
	Zombie *zombiePtr = newZombie("Zombie1");
	randomChump("Zombie2");
	delete zombiePtr;
}