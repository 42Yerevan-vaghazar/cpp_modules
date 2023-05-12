#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		BitcoinExchange obj("data.csv");
		parseFile(av[1], obj);
	} else {
		std::cerr << "Usage: ./btc [inputfile]" << std::endl;
	}
}
