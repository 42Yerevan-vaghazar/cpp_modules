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

	inline bool isLeapYear(int year) {
        return (year % 400 == 0 ? true : year % 100 == 0 ? false : year % 4 == 0 ? true : false);
    }
}

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const std::string &dbFileName) {
	std::ifstream ifs(dbFileName, std::ifstream::in);
	if (ifs.is_open()) {
		std::string line;
		std::getline(ifs, line, '\n');
		while (std::getline(ifs, line, '\n')) {
			std::pair<std::string, std::string> pair = ft::divide(line, ',');
			ft::strTrim(pair.first);
			ft::strTrim(pair.second);
			ValidDate(pair.first);
			m_dataVector.insert(pair);
		}
	} else {
		throw std::runtime_error("can't open file");
	}
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) {
	m_dataVector = rhs.m_dataVector;
};
BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		m_dataVector = rhs.m_dataVector;
	}
	return (*this);
};

void BitcoinExchange::printDB(void) const {
	std::pair<Map::const_iterator,Map::const_iterator> it( m_dataVector.begin(), m_dataVector.end());

	while (it.first != it.second) {
		std::cout << it.first->first << " : " << it.first->second << std::endl;
		it.first++;
	}
};

void BitcoinExchange::run(const std::string &fileName) {
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
				ValidValue(pair.second);
			} catch(const std::logic_error& e) {
				std::cerr << "Error: " << e.what() << "." << std::endl;
				continue ;
			}
			try {
				ValidDate(pair.first);
			} catch(const std::exception& e) {
				std::cerr << "Error: " << e.what() << "." << std::endl;
				continue ;
			}
			float amount = std::strtod(pair.second.c_str(), NULL);
			printExchangeMessage(pair.first, amount, this->exchange(pair.first, amount));
		}
	} else {
		throw std::runtime_error("can't open file");
	}
}

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

void BitcoinExchange::ValidDate(const std::string &date) {
	std::string arr[3];

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
	}
	for (int i = 0; i < 3; i++) {
		if (!ft::isNumber(arr[i])) {
			throw std::logic_error("bad input");
		}
	}
	errno = 0;
	std::strtol(arr[0].c_str(), NULL, 10);
	if (errno == ERANGE
		|| arr[1].size() != 2
		|| arr[2].size() != 2
		|| arr[1] > "12"
		|| arr[1] == "00"
		|| arr[2] == "00") {
		throw std::logic_error("bad input");
	}
	int monthNum = std::strtol(arr[1].c_str(), NULL, 10);
	int mod = monthNum % 2;
	if (monthNum == 2) {
		if (ft::isLeapYear(std::strtol(arr[0].c_str(), NULL, 10)) == true) {
			if (arr[2] > "29"){
				throw std::logic_error("bad inputa");
			}
		} else if (arr[2] > "28") {
			throw std::logic_error("bad input");
		}
	} else if (monthNum < 8) {
		if (mod == 0 && arr[2] > "30") {
			throw std::logic_error("bad input");
		}
		if (mod == 1 && arr[2] > "31") {
			throw std::logic_error("bad input");
		}
	} else {
		if (mod == 0 && arr[2] > "31") {
			throw std::logic_error("bad input");
		}
		if (mod == 1 && arr[2] > "30") {
			throw std::logic_error("bad input");
		}
	}
}

void BitcoinExchange::ValidValue(const std::string &value) {
	char *endPtr;

	double dval = std::strtod(value.c_str(), &endPtr);
	if (dval > 1000) {
		throw std::logic_error("too large a number");
	} else if (*endPtr != '\0' || dval == 0) {
		throw std::logic_error("bad input");
	} else if (dval < 0) {
		throw std::logic_error("not a positive number");
	}
}

void BitcoinExchange::printExchangeMessage(const std::string &date, float amount, double exchanged) {
	std::cout << date << " => " << amount << " = " << exchanged << std::endl;
}

