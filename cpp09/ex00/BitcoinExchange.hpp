#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <limits>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();
		void exec(std::string filename);
	private:
		bool can_open_input(std::string filename);
		bool read_data();
		bool validate_format(std::string line);
		bool validate_date(std::string date);
		bool validate_value(std::string line);
		void trim_space(std::string& line);
		void get_current_date();
		int _current_y;
		int _current_m;
		int _current_d;
		std::map<std::string, std::string> _data;
		void print_error(std::string str);
		bool is_before_first_record(int y, int m, int d);
		bool calculate_exchange_value(std::string line);
		std::string serach_near_date(std::string date);
};

 #endif
