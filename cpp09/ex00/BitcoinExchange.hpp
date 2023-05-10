#pragma once
#include <iostream>
#include <map>

typedef std::map<std::string, std::string> Map;

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &dbFileName);
        BitcoinExchange(const BitcoinExchange &obj);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        void isValidLine(const std::string &line, char del);
        std::pair<std::string, std::string>  split(const std::string &line, char del);
        void printDB(void) const;
    private:
        Map m_data;
};

bool isValidDate(const std::string &date);