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
	if (!ScalarConverter::validate_input(str))
	{
		ScalarConverter::print_impossible();
		return ;
	}
	if (!ScalarConverter::validate_overflow(str))
	{
		ScalarConverter::print_impossible();
		return ;
	}

	// 一回全部doubleにする
	// char c_val = 0;
	// int int_val = 0;
	// float f_val = 0;
	double d_val = 0;
	char* end;

    d_val = std::strtod(str.c_str(), &end);
	std::cout << "=== " << d_val << " ===" << std::endl;

	if (str.size() == 1 && isalpha(str[0]))
		return (ScalarConverter::print_char(str));

	bool point_flg = false;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (str[i] == '.')
			point_flg = true;
	}

	if (point_flg == false
		&& ((d_val > std::numeric_limits<int>::min()
		&& d_val < std::numeric_limits<int>::max())
		|| str == "2147483647" || str == "-2147483648"))
		return (ScalarConverter::print_int(str));

	// if (d_val < std::numeric_limits<char>::min() || d_val > std::numeric_limits<char>::max())
	// 		std::cout << "char: immposible" << std::endl;
	// else
	// {
	// 	c_val = static_cast<char>(d_val);
	// 	if (isprint(c_val))
	// 		std::cout << "char: " << c_val << std::endl;
	// 	else
	// 		std::cout << "char: Non displayable" << std::endl;
	// }
	// if (d_val < std::numeric_limits<int>::min() || d_val > std::numeric_limits<int>::max())
	// 	std::cout << "int :immposible" << std::endl;
	// else
	// {
	// 	int_val = static_cast<int>(d_val);
	// 	std::cout << "int :" << int_val << std::endl;
	// }

	// if (d_val < std::numeric_limits<float>::min() || d_val > std::numeric_limits<float>::max())
	// 	std::cout << "float :immposible" << std::endl;
	// else
	// {
	// 	f_val = static_cast<float>(d_val);
	// 	std::cout << "float :" << f_val << std::endl;
	// }
	// std::cout << "double :" << d_val << std::endl;

}

bool ScalarConverter::validate_input(std::string str)
 {
	if (str.size() == 1 && isprint(str[0]))
			return (true);

	int point_count = 0;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (isdigit(str[i]))
			continue ;
		else if (i == 0 && str[i] == '-')
			continue ;
		else if (i == (int)str.size() - 1 && str[i] == 'f')
			continue ;
		else if (str[i] == '.')
		{
			if (i == 0 || i == (int)str.size() - 1)
				return (false);
			point_count++;
			continue ;
		}
		else
			return (false);
	}
	if (point_count == 1 || point_count == 0)
		return (true);
	return (false);
 }

bool ScalarConverter::validate_overflow(std::string str)
 {
	double d_val = 0;
	char* end;
	errno = 0;

	d_val = std::strtod(str.c_str(), &end);
	if (errno == ERANGE)
		return (false);
	return (true);
 }

void	ScalarConverter::print_impossible()
 {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" <<  std::endl;
 }

void ScalarConverter::print_char(std::string str)
{
	std::stringstream ss;
	char c_val;
	int int_val;
	float f_val;
	double d_val;

	ss << str;
	ss >> c_val;

	int_val = static_cast<int>(c_val);
	f_val = static_cast<float>(c_val);
	d_val = static_cast<double>(c_val);
	std::cout << "char :" << c_val << std::endl;
	std::cout << "int :" << int_val << std::endl;
	std::cout << "float :" << f_val << std::endl;
	std::cout << "double :" << d_val << std::endl;
}

void ScalarConverter::print_int(std::string str)
{
	char c_val = 0;
	int int_val = 0;
	float f_val = 0;
	double d_val = 0;

	std::stringstream ss;
	ss << str;
	ss >> int_val;
	c_val = static_cast<char>(int_val);
	f_val = static_cast<float>(int_val);
	d_val = static_cast<double>(int_val);
	if (isprint(c_val))
		std::cout << "char :" << c_val << std::endl;
	else if (0 < int_val && int_val < 128)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int :" << int_val << std::endl;
	std::cout << "float :" << f_val << std::endl;
	std::cout << "double :" << d_val << std::endl;
}

 /*

 //test case
int max
2147483647

double max
179769313486231570000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
*/
