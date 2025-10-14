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

void CastUtil::print_all_integer(char c, int num, double d, float f)
{
	if (31 < num && num < 127)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << num << std::endl;

	if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d <<  std::endl;
}

