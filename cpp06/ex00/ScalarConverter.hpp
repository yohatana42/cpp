#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

 #include <string>
 #include <iostream>
 #include <sstream>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();
		static void convert(std::string str);
	private:
		// void chenge_char(std::stringstream ss);
		// void chenge_int(std::stringstream ss);
		// void chenge_float(std::stringstream ss);
		// void chenge_double(std::stringstream ss);

};

#endif
