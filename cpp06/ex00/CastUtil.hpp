#ifndef CASTUTIL_HPP
 #define CASTUTIL_HPP

class CastUtil
{
	public:
		CastUtil();
		CastUtil(const CastUtil& src);
		CastUtil& operator=(const CastUtil& src);
		~CastUtil();
		static void cast_char();
		static void print_all(char c, int num, double d, float f);
};

#endif
