#include <vector>
#include <stack>
#include <array>
#include <deque>
#include <forward_list>
#include "Span.hpp"
#include <random>

// int main()
// {
//     std::srand(unsigned(std::time(nullptr)));
//     std::vector<int> v(1000);
//     std::generate(v.begin(), v.end(), std::rand);
//     Span sp = Span(1000);
//     sp.fillSpan(v.begin(), v.end());
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

