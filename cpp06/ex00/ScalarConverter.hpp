#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <string>
 #include <iostream>
 #include <sstream>
 #include <stdlib.h>
 #include <cstdlib>
 #include <iomanip>
 #include <cerrno>
 #include <limits>

#include <cfloat>
#include <cmath>

class ScalarConverter
{
	public:
		static void convert(std::string str);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();
		static bool validate_input(std::string str);
		static bool validate_overflow(std::string str);
		static void	print_impossible();
		static void print_char(std::string str);
		static void print_int(std::string str);
		static void print_float_and_double(double d_val);

};

#endif
