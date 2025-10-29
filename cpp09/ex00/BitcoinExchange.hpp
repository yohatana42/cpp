#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <limits>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();
		void exec(std::string filename);
	private:
		bool validate_input(std::string filename);
		// bool read_input(std::string filename);
		// bool read_data();
		// std::fstream read_data();
		bool validate_format(std::string line);
		bool validate_date(std::string date);
		bool validate_value(std::string line);
		std::fstream _csv;
		void trim_space(std::string& line);
};

 #endif
