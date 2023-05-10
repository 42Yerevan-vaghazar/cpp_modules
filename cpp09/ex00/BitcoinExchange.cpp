#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const std::string &dbFileName) {
    std::ifstream ifs(dbFileName, std::ifstream::in);

    if (ifs.is_open()) {
        std::string line;
        while (std::getline(ifs, line, '\n')) {
            try {
                std::pair<std::string, std::string> pair = split(line, ',');
                std::cout << isValidDate(pair.first);
                std::cout << std::endl;
                m_data.insert(pair);
            } catch(const std::exception& e) {
                continue ;
                // std::cerr << e.what() << '\n';
            }
        }
        // printDB();
    } else {
        throw std::runtime_error("can't open file");
    }
};

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj);
BitcoinExchange::~BitcoinExchange() {};
// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj);


bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) {
        ++it;
    }
    return (!s.empty() && it == s.end());
}

// char **mySplit(const std::string &line, char del) {
//     int count;
//     char **result;

//     while (line.find('-') != std::string::npos) {
//         count++;
//     }
    
//     result = 
//     size_t pos = line.find(del);
//     std::string first;
//     std::string second;
//     if (pos !=  std::string::npos) {
//         first = line.substr(0, pos);
//         second = line.substr(pos + 1);
//     } else {
//         throw std::logic_error("there is not delimitr");
//     }
//     return (result);
// };


bool isValidDate(const std::string &date) {
    std::string arr[3];
    size_t pos = 0;
    size_t posTmp = 0;

    for (int i = 0; i < 3; i++) {
        if (pos == std::string::npos) {
            return (false);
        }
        pos = date.find('-');
        arr[i] = date.substr(posTmp, pos);
        std::cout << " arr[i] = " <<  arr[i] << std::endl;
        // if (!is_number(arr[i])) {
        //     return (false);
        // } 
        // else {
        //     return (false);
        // }
        posTmp = pos;
    }
    // if (arr[1].size() != 2 || std::strtol(arr[1].c_str(), NULL, 10)) {
    //     return (false);
    // }
    return (true);
}

// bool BitcoinExchange::isValidLine(const std::string &line, char del) {
    
// };

std::pair<std::string, std::string> BitcoinExchange::split(const std::string &line, char del) {
    size_t pos = line.find(del);
    std::string first;
    std::string second;
    if (pos !=  std::string::npos) {
        first = line.substr(0, pos);
        second = line.substr(pos + 1);
    } else {
        throw std::logic_error("there is not delimitr");
    }
    return (std::make_pair(first, second));
};


void BitcoinExchange::printDB(void) const {
    std::pair<Map::const_iterator,Map::const_iterator> it( m_data.begin(), m_data.end());

    while (it.first != it.second) {
        std::cout << it.first->first << " : " << it.first->second << std::endl;
        it.first++;
    }
};