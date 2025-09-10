#ifndef CASTUTIL_HPP
 #define CASTUTIL_HPP

 #include <iostream>
 #include <string>

class CastUtil
{
	public:
		CastUtil();
		CastUtil(const CastUtil& src);
		CastUtil& operator=(const CastUtil& src);
		~CastUtil();
		static void cast_char();
		static void print_all(char c, int num, double d, float f);
		// static void print_all(std::string c_str, std::string num_str, double d, float f);
		static void print_all(std::string c_str, std::string num_str, std::string d, std::string f);
};

#endif
