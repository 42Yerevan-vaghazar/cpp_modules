#pragma once
#include <iostream>
#include <map>

typedef std::map<std::string, std::string> Map;
typedef std::pair<std::string, std::string> Pair;

namespace ft
{
	bool isNumber(const std::string& s);
	std::pair<std::string, std::string> divide(const std::string &line, char del);
	inline std::string &strTrim(std::string &str);
    inline bool isLeapYear(int year);
}

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &dbFileName);
        BitcoinExchange(const BitcoinExchange &rhs);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        void printDB(void) const;
        void run(const std::string &inputFile);
    private:
        double exchange(const std::string &date, float amount) const;
        void ValidDate(const std::string &date);
        void ValidValue(const std::string &value);
        void printExchangeMessage(const std::string &date, float amount, double exchanged);
    private:
        Map m_dataVector;
};
