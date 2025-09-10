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
	char char_val = 0;
	int int_val = 0;
	double double_val = 0.0;
	float float_val = 0.0f;

	// ss << str;
	// while (ss.eof())
	// 	ss >> char_val;
	// std::cout << char_val << std::endl;

	ss << str;
	ss >> int_val;
	if (ss.fail())
	{
		std::cerr << "ss fail" << std::endl;
	}
	while (ss.eof()|| ss.fail())
		ss >> char_val;
	ss.clear();

	ss << str;
	ss >> double_val;
	while (ss.eof() || ss.fail())
		ss >> char_val;
	ss.clear();

	ss << str;
	ss >> float_val;
	while (ss.eof())
		ss >> char_val;

		// ????????
// 	c6r3s5% ./ex00 49.1
// char: Non displayable
// int: 49
// float: 0.149f
// double: 0.149


	CastUtil::print_all(char_val, int_val, double_val, float_val);

	// if (str.size() == 1 && isalpha(str[0]))
	// {
	// 	print_char = str[0];
	// 	print_int = print_char;
	// 	std::cout << print_int << std::endl;
	// 	print_double = print_char;
	// 	print_float = print_char;
	// 	return (CastUtil::print_all(print_char, print_int, print_double, print_float));
	// }

	// for (int i = 0;str[i] != '\0';i++)
	// {
	// 	if (isdigit(str[i]) || str[i] == '.' || (str[i] == 'f' && i == (int)str.size() - 1)
	// 	|| (i == 0 && (str[i] == '-' || str[i] == '+')))
	// 		continue ;
	// 	else
	// 		return CastUtil::print_all("impossible", "impossible", "impossible", "impossible");
	// }

	// // intの場合
	// // 2147483647 10桁
	// print_int = static_cast<int>(str);
	// print_char = print_int;
	// print_double = print_int;
	// print_float = print_int;
	// return CastUtil::print_all("impossible", "impossible", "impossible", "impossible");
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
