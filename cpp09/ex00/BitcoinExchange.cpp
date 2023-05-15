#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cerrno>

namespace ft
{
	bool isNumber(const std::string& s)
	{
		std::string::const_iterator it = s.begin();
		while (it != s.end() && std::isdigit(*it)) {
			++it;
		}
		return (!s.empty() && it == s.end());
	}

	std::pair<std::string, std::string> divide(const std::string &line, char del) {
		size_t pos = line.find(del);
		std::string first;
		std::string second;
		if (pos !=  std::string::npos) {
			first = line.substr(0, pos);
			second = line.substr(pos + 1);
			// std::cout << "second = " << second << std::endl;
		} else {
			throw std::logic_error("bad input");
		}
		return (std::make_pair(first, second));
	};

	static bool isSpace(int c) {
		return (!std::isspace(c));
	}

	inline std::string &strTrim(std::string &str) {
		str.erase(str.begin(), std::find_if(str.begin(), str.end(), isSpace));
		str.erase(std::find_if(str.rbegin(), str.rend(), isSpace).base(), str.end());
		return (str);
	}
}

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const std::string &dbFileName) {
	std::ifstream ifs(dbFileName, std::ifstream::in);
	if (ifs.is_open()) {
		std::string line;
		while (std::getline(ifs, line, '\n')) {
			try {
				// std::pair<std::string, std::string> pair = ft::divide(line, ',');
				std::pair<std::string, std::string> pair = ft::divide(line, ',');
				ft::strTrim(pair.first);
				ft::strTrim(pair.second);
				if (isValidDate(pair.first) == false) {
					// std::cerr << "invalid date" << std::endl;
					continue ;
				}
				// std::cout << isValidLine(pair.first);
				// std::cout << std::endl;
				m_dataVector.insert(pair);
			} catch(const std::exception& e) {
				continue ;
				// std::cerr << e.what() << '\n';
			}
		}
		// printDB();
	} else {
		// perror("open");
		throw std::runtime_error("can't open file");
	}
};

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj);
BitcoinExchange::~BitcoinExchange() {};
// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj);

std::string BitcoinExchange::getValue(const std::string &date) const {
	Map::const_iterator it = m_dataVector.find(date);

	if (it == m_dataVector.end()) {
		throw std::logic_error("there is not such date");
	}
	return (it->second);
};

void BitcoinExchange::setValue(const std::string &date, const std::string &value) {
	m_dataVector[date] = value;
};

double BitcoinExchange::exchange(const std::string &date, float amount) const {
	Map::const_iterator it;

	if (m_dataVector.size() < 1) {
		throw std::logic_error("there is not data");
	}
	it = m_dataVector.find(date);
	if (it != m_dataVector.end()) {
		return (strtod(it->second.c_str(), NULL) * amount);
	}
	std::pair<Map::const_iterator, Map::const_iterator> pair(m_dataVector.begin(), m_dataVector.end());
	while (pair.first != pair.second && pair.first->first < date) {
		++pair.first;
	}
	--pair.first;
	
	return (strtod(pair.first->second.c_str(), NULL) * amount);
};

bool isValidDate(const std::string &date) {
	std::string arr[3];

		// std::cout << "date = " << date << std::endl;
	try
	{
		Pair pair = ft::divide(date, '-');
		arr[0] = pair.first;
		pair = ft::divide(pair.second, '-');
		arr[1] = pair.first;
		arr[2] = pair.second;
	}
	catch(const std::logic_error& e)
	{
		throw std::logic_error("bad input");
		return (false);
	}
	for (int i = 0; i < 3; i++) {
		if (!ft::isNumber(arr[i])) {
			return (false);
		}
	}
	errno = 0;
	std::strtol(arr[0].c_str(), NULL, 10);
	if (errno == ERANGE
		|| arr[1].size() != 2
		|| arr[2].size() != 2
		|| arr[1] > "12"
		|| arr[2] == "00") {
		throw std::logic_error("bad inputa");
		return (false);
	}
	int monthNum = std::strtol(arr[1].c_str(), NULL, 10);
	int mod = monthNum % 2;
	if (monthNum < 8) {
		if (mod == 0 && arr[2] > "30") {
			throw std::logic_error("bad inputa");
		}
		if (mod == 1 && arr[2] > "31") {
			throw std::logic_error("bad inputa");
		}
	} else {
		if (mod == 0 && arr[2] > "31") {
			throw std::logic_error("bad inputa");
		}
		if (mod == 1 && arr[2] > "30") {
			throw std::logic_error("bad inputa");
		}
	}
	return (true);
}

bool isValidValue(const std::string &value) {
	char *endPtr;

	double dval = std::strtod(value.c_str(), &endPtr);
	if (dval > 1000) {
		throw std::logic_error("too large a number");
	} else if (*endPtr != '\0') {
		throw std::logic_error("bad input");
	} else if (dval < 0) {
		throw std::logic_error("not a positive number");
	}
	return (true);
}

bool isValidLine(const std::string &line) {
	if (isValidDate(line) == false) {
		std::cerr << "invalid date" << std::endl;
	}
	// if (isValidValue(line) == false) {
	//     std::cerr << "invalid value" << std::endl;
	// }
	return (true);
};

void BitcoinExchange::printDB(void) const {
	std::pair<Map::const_iterator,Map::const_iterator> it( m_dataVector.begin(), m_dataVector.end());

	while (it.first != it.second) {
		std::cout << it.first->first << " : " << it.first->second << std::endl;
		it.first++;
	}
};

void parseFile(const std::string &fileName, BitcoinExchange &data) {
	std::ifstream ifs(fileName, std::ifstream::in);

	if (ifs.is_open()) {
		std::string line;
		std::getline(ifs, line, '\n');
		while (std::getline(ifs, line, '\n')) {
			std::pair<std::string, std::string> pair;
			try {
				pair = ft::divide(line, '|');
				ft::strTrim(pair.first);
				ft::strTrim(pair.second);
			} catch(const std::logic_error& e)
			{
				std::cerr << "Error: " << e.what() << " => " << line << std::endl;
				continue ;
			} try {
				pair = ft::divide(line, '|');
				ft::strTrim(pair.first);
				ft::strTrim(pair.second);
				isValidValue(pair.second);
			} catch(const std::logic_error& e) {
				std::cerr << "Error: " << e.what() << "." << std::endl;
				continue ;
			}
			try {
				isValidDate(pair.first);
			} catch(const std::exception& e) {
				std::cerr << "Error: " << e.what() << "." << std::endl;
				continue ;
			}
			float amount = std::strtod(pair.second.c_str(), NULL);
			printExchangeMessage(pair.first, amount, data.exchange(pair.first, amount));
		}
	} else {
		perror("open");
		throw std::runtime_error("can't open file");
	}
}

void printExchangeMessage(const std::string &date, float amount, double exchanged) {
	std::cout << date << " => " << amount << " = " << exchanged << std::endl;
}

