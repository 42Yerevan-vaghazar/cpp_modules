#pragma once
#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack() {};
        MutantStack(const MutantStack &obj) : std::stack<T>(obj) {};
        ~MutantStack() {};
        MutantStack &operator=(const MutantStack &obj) {
            if (this != &obj) {
                this->stack::operator=(obj);
            }
            return (*this);
        };
        iterator begin() {
            return (this->c.begin());
        }
        iterator end() {
            return (this->c.end());
        }
};