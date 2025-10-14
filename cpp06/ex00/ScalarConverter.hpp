#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <string>
 #include <iostream>
 #include <sstream>
 #include <stdlib.h>
 #include <iomanip>
 #include <limits>
 #include "CastUtil.hpp"

class ScalarConverter
{
	public:
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();
		static void convert(std::string str);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		static bool cast_char(std::string str);
};

#endif
