#pragma once
#include <iostream>

class ScalarConverter
{
    public:
        static void convert(const std::string &str);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter&);
        static char m_character;;
        static int m_integer;;
        static float m_floatPoint;
        static double m_doublePoint;
        static std::string m_character_message;
        static std::string m_integer_message;
        static std::string m_floatPoint_message;
        static std::string m_doublePoint_message;
        static std::string m_literalType;
    private:
        static std::string determineTypeOfLiteral(const std::string &literal);
        static void castChar(char c);
        static void castInt(std::string num);
        static void castFloat(std::string num);
        static void castDouble(std::string num);
        static void printMassege(void);
        static void correctStrings(void);
};