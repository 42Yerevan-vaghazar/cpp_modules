#include "Serialization.hpp"

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    Data data;
    data.a = 5;
    data.b = 5.5;
    uintptr_t ptr;
    ptr = Serialization::serialize(&data);
    Data *dataPtr = Serialization::deserialize(ptr);
    std::cout << &data << std::endl;
    std::cout << dataPtr << std::endl;
    std::cout << dataPtr->a << std::endl;
    std::cout << dataPtr->b << std::endl;
}