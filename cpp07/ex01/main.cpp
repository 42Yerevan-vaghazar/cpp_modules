#include "iter.hpp"

template <typename T>
void print(T &a) {
    std::cout  << "a = " << a << std::endl;
};

int main( void ) {
    const int len = 10;
    const double a[len] = {1, 2, 3, 8, 1, 2, 5, 6, 7};
    const int b[len] = {1, 2, 3, 8, 1, 2, 5, 6, 7};
    iter<const double>(a, len, &print);
    iter<const int>(b, len, &print);
    for (size_t i = 0; i < len; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}