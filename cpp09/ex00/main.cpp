#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		BitcoinExchange obj("data.csv");
		parseFile(av[1], obj);
	} else {
		std::cerr << "Usage: ./btc [inputfile]" << std::endl;
	}
}


// // lower_bound/upper_bound example
// #include <iostream>     // std::cout
// #include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
// #include <vector>       // std::vector

// // int main () {
// //   int myints[] = {1, 2, 10, 12};
// //   std::vector<int> v(myints,myints+4);           // 10 20 30 30 20 10 10 20

// // //   std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

// //   std::vector<int>::iterator low,up;
// //   low = std::lower_bound(v.begin(), v.end(), 11); //          ^
// //   up = std::upper_bound(v.begin(), v.end(), 11); //                   ^

// //   std::cout << "lower_bound at position " << *low << '\n';
// //   std::cout << "upper_bound at position " << *up << '\n';

// //   return 0;
// // }