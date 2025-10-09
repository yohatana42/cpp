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

	// nanf nan
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" <<  std::endl;
	}
	else if (str == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inf" << std::endl;
		std::cout << "double: -inf" <<  std::endl;
	}
	else if (str == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inf" << std::endl;
		std::cout << "double: +inf" <<  std::endl;
	}

	if (str.size() == 1 && isalpha(str[0]))
	{
		std::cout << "-- char --" << std::endl;
		ss << str;
		ss >> char_val;
		int_val = static_cast<int>(char_val);
		double_val = static_cast<double>(int_val);
		float_val = static_cast<float>(int_val);
		CastUtil::print_all_integer(char_val, int_val, double_val, float_val);
		return ;
	}
	else if (str.find('.') == std::string::npos)
	{
		std::cout << "== int ==" << std::endl;
		ss << str;
		ss >> int_val;
		if (ss.fail())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" <<  std::endl;
			return ;
		}
		// intの場合
		char_val = static_cast<char>(int_val);
		double_val = static_cast<double>(int_val);
		float_val = static_cast<float>(int_val);
		CastUtil::print_all_integer(char_val, int_val, double_val, float_val);
		return ;
	}
	if (str.find('f') == str.size() - 1)
	{
		std::cout << "~~ float ~~" << std::endl;
		ss << str;
		ss >> float_val;
		if (ss.fail())
			std::cerr << "ss fail" << std::endl;
		char_val = static_cast<char>(float_val);
		int_val = static_cast<int>(float_val);
		double_val = static_cast<double>(float_val);
		CastUtil::print_all(char_val, int_val, double_val, float_val);
		return ;
	}
	else
	{
		std::cout << "'' double ''" << std::endl;
		ss << str;
		ss >> double_val;
		if (ss.fail())
			std::cerr << "ss fail" << std::endl;
		char_val = static_cast<char>(double_val);
		int_val = static_cast<int>(double_val);
		float_val = static_cast<double>(double_val);
		CastUtil::print_all(char_val, int_val, double_val, float_val);
		return ;
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" <<  std::endl;

}
