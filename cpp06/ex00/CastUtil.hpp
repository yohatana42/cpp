#ifndef CASTUTIL_HPP
 #define CASTUTIL_HPP

 #include <iostream>
 #include <string>
 #include <iomanip>

class CastUtil
{
	public:
		CastUtil();
		CastUtil(const CastUtil& src);
		CastUtil& operator=(const CastUtil& src);
		~CastUtil();
		static void cast_char(std::string str);
		static void print_all(char c, int num, double d, float f);
		static void print_all_integer(char c, int num, double d, float f);
};

#endif
