#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 2;
    Zombie *zombieArr = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++) {
        zombieArr[i].announce();
    }
    delete[] zombieArr;
}