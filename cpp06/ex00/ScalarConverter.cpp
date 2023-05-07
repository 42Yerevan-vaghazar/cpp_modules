#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <cstring>

std::string ScalarConverter::m_literalType;
std::string ScalarConverter::m_character_message;
std::string ScalarConverter::m_integer_message;
std::string ScalarConverter::m_floatPoint_message;
std::string ScalarConverter::m_doublePoint_message;

char ScalarConverter::m_character;;
int ScalarConverter::m_integer;;
float ScalarConverter::m_floatPoint;
double ScalarConverter::m_doublePoint;

void ScalarConverter::convert(const std::string &str) {
	try {
		m_literalType = determineTypeOfLiteral(str);
		// std::cout << "m_literalType = " << m_literalType << std::endl;
		if (m_literalType == "char") {
			castChar(str[0]);
		} else if (m_literalType == "int") {
			castInt(str);
		} else if (m_literalType == "float") {
			castFloat(str);
		} else if (m_literalType == "double") {
			castDouble(str);
		}
        ScalarConverter::printMassege();
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}
};

bool isDouble(const std::string &literal) {
	bool dotSeen = false;
	size_t i = 0;

	if (literal == "-inf" || literal == "+inf" || literal == "nan") {
		return (true);
	}
	if (literal[i] == '+' || literal[i] == '-') {
		++i;
	}
	for (; i < literal.length(); i++) {
		if ((isdigit(literal[i]) == false && literal[i] != '.')
			|| (literal[i] == '.'
			&& dotSeen == true)) {
			return (false);
		}
		if (literal[i] == '.') {
			dotSeen = true;
		}
	}
	return (dotSeen);
}

bool isFloat(const std::string &literal) {
	bool dotSeen = false;
	size_t i = 0;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		return (true);
	}
	if (literal[i] == '+' || literal[i] == '-') {
		++i;
	}
	for (; i < literal.length(); i++) {
		if ((isdigit(literal[i]) == false && literal[i] != '.' && literal[i] != 'f')
			|| (literal[i] == '.'
			&& dotSeen == true)) {
			return (false);
		}
		if (literal[i] == 'f' && i != literal.length() - 1) {
			return (false);
		}
		if (literal[i] == '.') {
			dotSeen = true;
		}
	}
	return (dotSeen && literal[literal.length() - 1] == 'f');
}

bool isInt(const std::string &literal) {
	size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-') {
		++i;
	}
	if (literal[i] == '0' && (literal.length() - i) > 1) {
		return (false);
	}
	for (; i < literal.length(); i++) {
		if ((isdigit(literal[i]) == false)) {
			return (false);
		}
	}
	return (true);
}

std::string ScalarConverter::determineTypeOfLiteral(const std::string &literal) {
	if (isInt(literal))
		return ("int");
	if (literal.length() == 1 && isprint(literal[0]))
		return ("char");
	if (isFloat(literal))
		return ("float");
	if (isDouble(literal))
		return ("double");
	throw std::runtime_error("Non displayable");
	return ("");
};

void ScalarConverter::castChar(char c) {
    m_character = c;
	m_integer = (static_cast<int>(c));
	m_floatPoint = (static_cast<float>(c));
	m_doublePoint = (static_cast<double>(c));
}

void ScalarConverter::castInt(std::string num) {
	char    *endptr;
	double	numTmp;

	numTmp = std::strtod(num.c_str(), &endptr);
	if ((numTmp > std::numeric_limits<int>::max() || (numTmp < std::numeric_limits<int>::min()))) {
		throw std::runtime_error("int: impossible");
	} else {
		m_integer = (static_cast<int>(numTmp));  //TODO check corectness
	}
	if (m_integer > std::numeric_limits<char>::max()
		|| m_integer < std::numeric_limits<char>::min()) {
		m_character_message = "impossible";
	} else if (isprint(m_integer) == false) {
		m_character_message = "Non displayable";
	} else {
		m_character = (static_cast<char>(m_integer));
	}
	m_floatPoint = (static_cast<float>(m_integer));  //TODO check corectness
	m_doublePoint = (static_cast<double>(m_integer));
}

void ScalarConverter::castFloat(std::string num) {
	char    *endptr;
	double	numTmp;

	numTmp = std::strtod(num.c_str(), &endptr);
	m_floatPoint = static_cast<float>(numTmp);
	if (m_floatPoint != m_floatPoint  || static_cast<int>(m_floatPoint) > std::numeric_limits<char>::max()
		|| static_cast<int>(m_floatPoint) < std::numeric_limits<char>::min()) {
		m_character_message = "impossible";
	} else if (isprint(static_cast<int>(m_floatPoint)) == false) {
		m_character_message = "Non displayable";
	} else {
		m_character = (static_cast<char>(m_floatPoint));
	}
	if (m_floatPoint != m_floatPoint || (m_floatPoint > std::numeric_limits<int>::max() || (m_floatPoint < std::numeric_limits<int>::min()))) {
		m_integer_message = "impossible";
	} else {
		m_integer = (static_cast<int>(m_floatPoint));
	}
	m_doublePoint = (static_cast<double>(m_floatPoint));
}

void ScalarConverter::castDouble(std::string num) {
	char    *endptr;
	double	numTmp;

	numTmp = std::strtod(num.c_str(), &endptr);
	m_doublePoint = static_cast<double>(numTmp);
	if (numTmp != numTmp  || static_cast<int>(numTmp) > std::numeric_limits<char>::max()
		|| static_cast<int>(numTmp) < std::numeric_limits<char>::min()) {
		m_character_message = "impossible";
	} else if (isprint(static_cast<int>(m_floatPoint)) == false) {
		m_character_message = "Non displayable";
	} else {
		m_character = (static_cast<char>(m_doublePoint));
	}
	if (numTmp != numTmp || (numTmp > std::numeric_limits<int>::max() || (numTmp < std::numeric_limits<int>::min()))) {
		m_integer_message = "impossible";
	} else {
		m_integer = (static_cast<int>(m_doublePoint));
	}
	m_floatPoint = (static_cast<float>(m_doublePoint));
}

void ScalarConverter::printMassege(void) {
	if (m_character_message.empty()) {
		std::cout << "char: '" << m_character << "'" << std::endl;
	} else {
		std::cout << "char: " << m_character_message << std::endl;
	}
	if (m_integer_message.empty()) {
		std::cout << "int: " << m_integer << std::endl;
	} else {
		std::cout << "int: " << m_integer_message << std::endl;
	}
	if (m_floatPoint_message.empty()) {
		double intpart;
		std::cout << "float: " << m_floatPoint;
		if (modf(m_floatPoint, &intpart) == 0 && m_doublePoint != HUGE_VAL && m_doublePoint != -HUGE_VAL) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	} else {
		std::cout << "float: " << m_floatPoint_message << std::endl;
	}
	if (m_doublePoint_message.empty()) {
		double intpart;
		std::cout << "double: " << m_doublePoint;
		if (modf(m_doublePoint, &intpart) == 0 && m_doublePoint != HUGE_VAL && m_doublePoint != -HUGE_VAL) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	} else {
		std::cout << "double: " << m_doublePoint_message << std::endl;
	}
};

