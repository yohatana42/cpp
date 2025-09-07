#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string str)
{
	chenge_char(str);
	chenge_int(str);
	chenge_float(str);
	chenge_double(str);
	std::cout << "" << std::endl;
}

static void chenge_char(std::string str)
{
	std::stringstream ss;
	for (int i = 0;str[i] != '\0', i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "" << std::endl;
		}
	}
	int num;
	ss << str;
	ss >> num;
}

static void chenge_int(std::string str)
{
	std::stringstream ss;
	ss << str;
}

static void chenge_float(std::string str)
{
	std::stringstream ss;
	ss << str;
}

static void chenge_double(std::string str)
{
	std::stringstream ss;
	ss << str;
}
