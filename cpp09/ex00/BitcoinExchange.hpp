#pragma once
#include <iostream>
#include <map>

typedef std::map<std::string, std::string> Map;
typedef std::pair<std::string, std::string> Pair;

// enum DaysOfMonths
// {

// }

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &dbFileName);
        BitcoinExchange(const BitcoinExchange &obj);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        void printDB(void) const;
        void setValue(const std::string &date, const std::string &value);
        std::string getValue(const std::string &date) const;
        double exchange(const std::string &date, float amount) const;
    private:
        Map m_dataVector;
};

bool isValidDate(const std::string &date);
std::pair<std::string, std::string>  divide(const std::string &line, char del);
bool isValidLine(const std::string &line);
inline std::string &strTrim(std::string &str);
void parseFile(const std::string &fileName, BitcoinExchange &data);
void printExchangeMessage(const std::string &date, float amount, double exchanged);