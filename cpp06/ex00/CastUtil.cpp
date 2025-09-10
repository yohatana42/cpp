#include "CastUtil.hpp"

CastUtil::CastUtil() {}

CastUtil::CastUtil(const CastUtil& src)
{
	(void)src;
}

CastUtil& CastUtil::operator=(const CastUtil& src)
{
	(void)src;
	return (*this);
}

CastUtil::~CastUtil() {}

void CastUtil::cast_char()
{

}

void CastUtil::print_all(char c, int num, double d, float f)
{
	if (31 < c && c < 127)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << d << "f" << std::endl;
	std::cout << "double: " << f <<  std::endl;
}

// void CastUtil::print_all(std::string c_str, std::string num_str, double d, float f)
// {
// 	std::cout << "char: " << c_str << std::endl;
// 	std::cout << "int: " << num_str << std::endl;
// 	std::cout << "float: " << d << "f" << std::endl;
// 	std::cout << "double: " << f <<  std::endl;
// }

void CastUtil::print_all(std::string c_str, std::string num_str, std::string d, std::string f)
{
	std::cout << "char: " << c_str << std::endl;
	std::cout << "int: " << num_str << std::endl;
	std::cout << "float: " << d << std::endl;
	std::cout << "double: " << f <<  std::endl;
}
