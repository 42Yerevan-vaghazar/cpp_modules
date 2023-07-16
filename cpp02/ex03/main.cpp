#include <iostream>
#include "Fixed.hpp"

#include "Point.hpp"

int main( void ) {
    if (bsp(Point(1, 1), Point(1, 5), Point(5, 1), Point(1, 3)) == true) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    };
    if (bsp(Point(1, 1), Point(1, 5), Point(5, 1), Point(2, 3)) == true) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    };
}