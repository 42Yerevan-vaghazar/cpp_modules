#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
    Cat a = Cat();
    Cat b = a;
    }

    const int count = 10;
    Animal *a[count];
    int i = 0;
    for (; i < count / 2; i++) {
        a[i] = new Dog();
    }
    for (; i < count; i++) {
        a[i] = new Cat();
    }
    for (int i = 0; i < count; i++) {
        delete a[i];
    }
    // system("leaks animal");
    return 0;
}

// void func(const Cat* j) {
//     delete [] j ;
// }

// int main()
// {
//     const Cat* j = new Cat[5] ;
//     func(j);

//     // delete [] j ;
// }