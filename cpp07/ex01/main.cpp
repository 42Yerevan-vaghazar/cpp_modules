#include "iter.hpp"

template <typename T>

void func(T &a) {
    a += 10;
};

int main( void ) {
    const int len = 10;
    double a[len] = {1, 2, 3, 8, 1, 2, 5, 6, 7};
    iter(a, len, &func);
    for (size_t i = 0; i < len; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}