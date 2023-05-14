#include <iostream>
#include <utility>
#include "PmergeMe.hpp"

int ft_rand() {
    return (std::rand() % 100);
};

int main(int ac, char **av) {
    (void)ac;
    (void)av;

    if (ac > 1) {
        std::srand(unsigned(std::time(nullptr)));
        std::vector<int> v(std::strtol(av[1], NULL, 10));
        std::generate(v.begin(), v.end(), ft_rand);
        PmergeMe merge(v);
        // PmergeMe merge;
        // int i  = 1;
        // while (i < ac) {
        //     int tmp = std::strtol(av[i++], NULL, 10);
        //     merge.addNum(tmp);
        // }
        // merge.printData();
        merge.sortVector();
        // merge.printData();
        merge.isSorted();
    }
}
