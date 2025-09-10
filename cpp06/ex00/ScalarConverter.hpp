#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <string>
 #include <iostream>
 #include <sstream>
 #include <stdlib.h>
 #include <iomanip>
 #include <limits>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();
		static void convert(std::string str);
};

#endif
