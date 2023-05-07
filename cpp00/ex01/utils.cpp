#include <iostream>

bool isAllDigit(const std::string str)  {
	std::pair<std::string::const_iterator, std::string::const_iterator> it(str.begin(), str.end());
	while (it.first != it.second)
	{
		if (std::isdigit(*it.first) == false)
			break ;
		it.first++;
	}
	return (it.first == it.second);
}