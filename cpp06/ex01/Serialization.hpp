#pragma once
#include <iostream>

typedef struct Data
{
    int   a;
    float b;
}              Data;

class Serialization
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serialization();
        Serialization(const Serialization&);
        ~Serialization();
        Serialization& operator=(const Serialization&);
};