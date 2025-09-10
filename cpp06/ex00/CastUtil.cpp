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
	(void)c;
	(void)num;
	(void)d;
	(void)f;
}
