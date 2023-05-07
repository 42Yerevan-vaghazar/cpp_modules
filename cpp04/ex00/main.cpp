#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // float a = 5.5;

    // std::cout << (a & 4) << std::end;;
    // Animal a;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // const WrongAnimal* meta = new WrongAnimal();
    // const WrongAnimal* j = new WrongCat();
    // const WrongAnimal* i = new WrongCat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    // ...
    delete meta;
    delete i;
    delete j;
    return 0;
}