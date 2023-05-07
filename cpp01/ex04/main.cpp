#include <fstream>
#include <iostream>

// functiion description
// receives pathname of file as an argument and returns string containing file's content.
// throws exception when encountered error while reading.
std::string readFromFile(const char *pathname) {
	std::ifstream infile (pathname, std::ios::in | std::ios::binary);
	std::string strTemp;
	std::string strResult;
	if (infile.is_open()) {
		infile.seekg(0, infile.end);
		int	len = 1 + infile.tellg();
		if (len == 1) {
			throw "Error empty file";
		}
		infile.seekg(0, infile.beg);
		char *buf = new char[len];
		if (infile.get(buf, len, '\0')) {
			if (!infile.good()) {
				throw "Error while reading";
			}
			strResult.append(buf);
		}
	} else {
		throw "Error opening file";
	}
	return (strResult);
}

// functiion description
// receives pathname of file as an argument and writes string in it.
// throws exception when encountered error while writing.
void writeInFile(const std::string &pathName, const std::string &str) {
	std::ofstream outfile (pathName, std::ios::out | std::ios::binary);
	if (outfile.is_open()) {
		outfile << str;
		if (!outfile.good()) {
			throw "Error while reading";
		}
	} else {
		throw "Error opening file";
	}
}

std::string replace(std::string src, const std::string &oldStr, const std::string &newStr) {
	std::string result;
	size_t		start = 0;
	for (size_t pos = 0; pos != std::string::npos; ) {
		pos = src.find(oldStr, start);
		if (pos != std::string::npos) {
			result.append(src, start, pos - start);
			result.append(newStr);
			start = pos + oldStr.length();
		} else {
			result.append(src, start, src.length() - start);
			break ;
		}
	}
	return (result);
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "error: wrong number of arguments" << std::endl;
		std::cerr << "usage: ./raplace [filename] [old] [new]" << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		std::string pathName = av[1];
		writeInFile(pathName.append(".replace"), replace(readFromFile(av[1]), av[2], av[3]));

	} catch (const char *err) {
		std::cerr << err << std::endl;
	}
	return (EXIT_SUCCESS);
}