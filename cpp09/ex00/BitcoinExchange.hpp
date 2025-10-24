#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

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
		std::fstream BitcoinExchange::read_data();
		bool validate_format(std::string line);
		bool validate_date(std::string date);
		std::fstream _csv;
};

 #endif
