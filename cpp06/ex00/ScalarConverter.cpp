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

// オーバーフロー対策やる
void ScalarConverter::convert(std::string str)
{
	char print_char = 0;
	int print_int = 0;
	double print_double = 0.0;
	float print_float = 0.0f;

	if (str.size() == 1 && isprint(str[0]))
	{
		print_char = str[0];
		print_int = print_char;
		print_double = print_char;
		print_float = print_char;
	}

	for (int i = 0;str[i] != '\0';i++)
	{
		if (isdigit(str[i]) || str[i] == '.' || str[i] == 'f')
			continue ;
		else
		{
			std::cout << "!!! impossible !!!" << std::endl;
			return ;
		}
	}
	CastUtil::print_all(print_char, print_int, print_double, print_float);
	std::cout << "char: " << print_char << std::endl;
	std::cout << "int: " << print_int << std::endl;
	std::cout << "float: " << print_double << "f" << std::endl;
	std::cout << "double: " << print_float <<  std::endl;
}

/*
void ScalarConverter::convert(std::string str)
{
	int num;
	double double_num = 0.0;
	float float_num = 0;

	std::string print_char;
	std::string print_int;

	if (str == "nan" || str == "nanf")
	{
		float_num = std::numeric_limits<float>::quiet_NaN();
		double_num = std::numeric_limits<double>::quiet_NaN();
		print_char = "impossible";
		print_int = "impossible";
	}
	else if (str == "-inf" || str == "+inf")
	{
		print_char = "impossible";
		print_int = "impossible";
		float_num = std::numeric_limits<float>::infinity();
		double_num = std::numeric_limits<double>::infinity();
	}
	else if (str == "-inff" || str == "+inff")
	{
		print_char = "impossible";
		print_int = "impossible";
		float_num = std::numeric_limits<float>::infinity();
		double_num = std::numeric_limits<double>::infinity();
	}
	else
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '.' && i != 0 && i != (int)str.size() -1)
			{
				double_num = atof(str.c_str());
				float_num = static_cast<float>(double_num);
				print_char = "impossible";
				print_int = "impossible";
				std::cout << "char: " << print_char << std::endl;
				std::cout << "int: " << print_int << std::endl;
				std::cout << "float: " << float_num << "f" << std::endl;
				std::cout << "double: " << double_num <<  std::endl;
				return ;
			}
		}
		num = atoi(str.c_str());
		double_num = atof(str.c_str());
		float_num = static_cast<float>(double_num);
		if (31 < num && num < 127)
		std::cout << "char: " << "'" << (char)num << "'" << std::endl;
		else
		{
			std::cout << "char:  Non displayable" << std::endl;
			std::cout << "int: " << num << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << float_num << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << double_num <<  std::endl;
		}
		std::cout << "char: " << print_char << std::endl;
		std::cout << "int: " << print_int << std::endl;
		std::cout << "float: " << float_num << "f" << std::endl;
		std::cout << "double: " << double_num <<  std::endl;
	}
}
*/
