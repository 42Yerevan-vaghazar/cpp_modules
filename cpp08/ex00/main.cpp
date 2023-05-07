#include <vector>
#include <stack>
#include <array>
#include <deque>
#include <forward_list>
#include "easyFind.hpp"

int main() {
    const int count = 10;
    int myints[] = {16, 2, 77, 29, 88, 45, 23, 21, 79, 88};
    const int myintsSize = sizeof(myints) / sizeof(int);
    std::vector<int> a(myints, myints + myintsSize);
    std::vector<int>::iterator it =  easyfind(a, 21);
    std::cout << "vector" << std::endl;
    if (it != a.end()) {
        while (it != a.end()) {
            std::cout << *(it++) << " ";
        }
    } else {
        std::cout << "not found" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "vector" << std::endl;
    std::cout << "array" << std::endl;
    std::array<int, count> myArray = {16, 2, 77, 29, 88, 45, 23, 21, 79, 88};
    std::array<int, count>::iterator itArray = easyfind(myArray, 77);
    if (itArray != myArray.end()) {
        while (itArray != myArray.end()) {
            std::cout << *(itArray++) << " ";
        }
    } else {
        std::cout << "not found" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "array" << std::endl;

    std::cout << "deque" << std::endl;
    std::deque<int> myDeque(myints, myints + myintsSize);
    std::deque<int>::iterator itdeque = easyfind(myDeque, 77);
    if (itdeque != myDeque.end()) {
        while (itdeque != myDeque.end()) {
            std::cout << *(itdeque++) << " ";
        }
    } else {
        std::cout << "not found" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "deque" << std::endl;
    std::cout << "forward_list" << std::endl;
    std::forward_list<int> myforward_list(myints, myints + myintsSize);
    std::forward_list<int>::iterator itforward_list = easyfind(myforward_list, 23);
    if (itforward_list != myforward_list.end()) {
        while (itforward_list != myforward_list.end()) {
            std::cout << *(itforward_list++) << " ";
        }
    } else {
        std::cout << "not found" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "forward_list" << std::endl;
    // std::stack<int, std::vector<int> > myStack(a);
    // std::stack<int>::iterator itStack = easyfind(myStack, 21);
}