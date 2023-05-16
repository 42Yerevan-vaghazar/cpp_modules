#include <iostream>
#include <utility>
#include "PmergeMe.hpp"

int main(int ac, char **av) {
	(void)ac;
	(void)av;

	if (ac > 1) {
		try
		{
			PmergeMe merge;
			std::vector<int> numbers;
			int i  = 1;
			char *endPtr;
			while (i < ac) {
			    int tmp = std::strtol(av[i++], &endPtr, 10);
				if (*endPtr != '\0') {
					std::cerr << "Invalid arguments" << std::endl;
					return (1);
				}
			    numbers.push_back(tmp);
			}
			merge.fillContainer(numbers);
			merge.fillContainer(List(numbers.begin(), numbers.end()));
			double timeVectorStart = get_current_time();
			merge.sortVector();
			double timeVectorEnd = get_current_time();
			double timeListStart = get_current_time();
			merge.sortList();
			double timeListEnd = get_current_time();
			std::setprecision(3);
			std::cout << "Before:  ";
			merge.printDataBefore();
			std::cout << "After:   ";
			merge.printDataVector();
			std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector : " << (timeVectorEnd - timeVectorStart) / 1000 << " ms" << std::endl;
			std::cout << "Time to process a range of " << numbers.size() << " elements with std::list   : " << (timeListEnd - timeListStart) / 1000 << " ms" << std::endl;
			// merge.isSortedVector();
			// merge.isSortedList();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	} else {
		std::cout << "Usage: ./PmergeMe [1] [2] ..." << std::endl;
	}
}