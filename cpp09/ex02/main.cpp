#include <iostream>
#include <utility>
#include "PmergeMe.hpp"

// int ft_rand() {
//     return (std::rand() % 10000000);
// };

void startTime() {
     std::high_resolution_clock::time_point t1 = std::high_resolution_clock::now();
}

int main(int ac, char **av) {
    (void)ac;
    (void)av;

    if (ac > 1) {
        try
        {
            PmergeMe merge;
            merge.fillContainer(1000);
            // PmergeMe merge;
            // int i  = 1;
            // while (i < ac) {
            //     int tmp = std::strtol(av[i++], NULL, 10);
            //     merge.addNum(tmp);
            // }
            // // merge.printData();
            // merge.sortVector();
            // // merge.printData();
            // merge.isSorted();
            // merge.printDataList();
            // merge.printDataList();
            merge.sortList();
            merge.isSortedList();
            merge.sortVector();
            merge.isSortedVector();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
