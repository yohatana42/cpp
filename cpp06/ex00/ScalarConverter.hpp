#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <string>
 #include <iostream>
 #include <sstream>
 #include <stdlib.h>
 #include <cstdlib>
 #include <iomanip>
 #include <limits>
 #include "CastUtil.hpp"
 #include <cerrno>
 #include <limits>

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
