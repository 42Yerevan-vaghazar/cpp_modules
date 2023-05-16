#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		try {
			BitcoinExchange obj("data.csv");
			obj.run(av[1]);
		} catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	} else {
		std::cerr << "Usage: ./btc [inputfile]" << std::endl;
	}
}
