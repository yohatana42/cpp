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
	std::stringstream ss;
	ss << str;
	/*
		1 まず型を判別する
		2 atoi,atof(stdlib.h)で変換する
		3 charはintを変換する
		4 フロート型にするぜ（まじでよくわからん）
	*/
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "inf or nan" << std::endl;
	}
	else if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "inff or nanf" << std::endl;
	}
	else
	{
		int num;
		double double_num = 0;
		float float_num = 0;

		if (str[str.size() - 1] == 'f')
		{
			std::cout << "this is float" << std::endl;

			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << float_num << std::endl;
			std::cout << "double: " << double_num <<  std::endl;
		}
		else
		{
			num = atoi(str.c_str());
			double_num = atof(str.c_str());
			if (31 < num && num < 127)
				std::cout << "char: " << "'" << (char)num << "'" << std::endl;
			else
				std::cout << "char:  Non displayable" << std::endl;
			std::cout << "int: " << num << std::endl;
			std::cout << "float: " << float_num << std::endl;
			std::cout << "double: " << double_num <<  std::endl;
		}
	}
}
