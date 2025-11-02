#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	(void)src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	(void)src;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::exec(std::string filename)
{
	// initにするべき
	get_current_date();
	if (!read_data())
		return (print_error("Error :failed open data.csv"));
	if (!can_open_input(filename))
		return (print_error("Error :failed open input file"));

	std::fstream stream;
	stream.open(filename.c_str());
	if (!stream)
		return (print_error("Error :failed open input file"));

	std::string line;
	int i = 0;
	while (std::getline(stream, line))
	{
		if (i == 0)
		{
			++i;
			continue ;
		}
		if (!validate_format(line))
			continue ;
		calculate_exchange_value(line);
	}
	stream.close();
}

bool BitcoinExchange::can_open_input(std::string filename)
{
	std::fstream s;

	s.open(filename.c_str());
	if (!s)
		return (false);
	s.close();
	return (true);
}

bool BitcoinExchange::read_data()
{
	std::fstream stream;
	std::string line;

	stream.open("data.csv");
	if (!stream)
		return (false);

	int i = 0;
	int split_pos;

	std::string key;
	std::string val;
	while (std::getline(stream, line))
	{
		if (i == 0)
		{
			++i;
			continue ;
		}
		split_pos = line.find(",");
		key = line.substr(0, split_pos);
		val = line.substr(split_pos + 1, line.size() - (split_pos + 1));
		_data.insert(std::make_pair(key, val));
		std::getline(stream, line);
	}
	stream.close();
	return (true);
}

bool BitcoinExchange::validate_format(std::string line)
{
	int pipe_pos = line.find("|");
	int pipe_pos2 = line.rfind("|");
	if (pipe_pos == (int)std::string::npos || pipe_pos != pipe_pos2)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}

	trim_space(line);

	std::string date;
	std::string value;
	date = line.substr(0, pipe_pos - 1);
	value = line.substr(pipe_pos, line.size() - pipe_pos);

	if (!validate_date(date))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
	if (!validate_value(value))
		return (false);
	return (true);
}

bool BitcoinExchange::validate_date(std::string date)
{
	std::stringstream ss;
	int year;
	int month;
	int day;
	int m_array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (int i = 0; i < (int)date.size(); i++)
	{
		if (date[i] != '-' && !isdigit(date[i]))
			return (false);
	}

	int left_split_pos = date.find("-");
	int right_split_pos = date.rfind("-");

	ss.str("");
	ss << date.substr(0, left_split_pos);
	ss >> year;
	ss.clear();
	ss.str("");
	ss << date.substr(left_split_pos + 1, right_split_pos - (left_split_pos + 1));
	ss >> month;
	ss.clear();
	ss.str("");
	ss << date.substr(right_split_pos + 1);
	ss >> day;
	ss.clear();

	if ((_current_m < month && _current_y == year)
		|| (_current_d < day && _current_m == month && _current_y == year))
		return (false);

	if (_current_y < year)
		return (false);
	if (12 < month || month < 0)
		return (false);
	if (day < 1 || m_array[month - 1] < day
		|| (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
						&& m_array[month - 1] + 1 < day))
		return (false);
	if (is_before_first_record(year, month, day))
		return (false);

	return (true);
}

bool BitcoinExchange::is_before_first_record(int y, int m, int d)
{
	int f_year;
	int f_month;
	int f_day;
	std::string first_date;
	std::stringstream ss;

	std::map<std::string, std::string>::iterator it = _data.begin();
	first_date = it->first;

	int left_split_pos = first_date.find("-");
	int right_split_pos = first_date.rfind("-");

	ss << first_date.substr(0, left_split_pos);
	ss >> f_year;
	ss.clear();
	ss << first_date.substr(left_split_pos + 1, right_split_pos - (left_split_pos + 1));
	ss >> f_month;
	ss.clear();
	ss << first_date.substr(right_split_pos + 1, first_date.size());
	ss >> f_day;
	ss.clear();
	if (y < f_year)
		return (true);
	if (m < f_month)
		return (true);
	if (d < f_day)
		return (true);
	return (false);
}

bool BitcoinExchange::validate_value(std::string value)
{
	std::stringstream ss;
	double val;

	ss << value;
	ss >> val;
	if (val < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (1000 < val)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::trim_space(std::string& line)
{
	std::string left;
	std::string right;

	int space_pos = line.find(" ");
	while (space_pos > 0)
	{
		line.erase(space_pos, 1);
		space_pos = line.find(" ");
	}
}

void BitcoinExchange::get_current_date()
{
	time_t t;

	t = time(NULL);
	tm *d = localtime(&t);

	_current_y = d->tm_year + 1900;
	_current_m = d->tm_mon + 1;
	_current_d = d->tm_mday;
}

void BitcoinExchange::print_error(std::string str)
{
	std::cout << str << std::endl;
}

bool BitcoinExchange::calculate_exchange_value(std::string line)
{
	int pipe_pos = line.find("|");
	trim_space(line);
	std::string input_date = line.substr(0, pipe_pos - 1);
	std::string temp_val = line.substr(pipe_pos, line.size() - pipe_pos);

	double input_val;
	std::stringstream ss;
	ss << temp_val;
	ss >> input_val;
	ss.clear();

	std::string near_date;
	std::map<std::string, std::string>::iterator it = _data.find(input_date);
	if (it == _data.end())
	{
		near_date = serach_near_date(input_date);
		it = _data.find(near_date);
	}

	double data_val;

	ss << it->second;
	ss >> data_val;
	ss.clear();

	std::cout << input_date << " => " << input_val << " = " << input_val * data_val << std::endl;;
	return (true);
}

std::string BitcoinExchange::serach_near_date(std::string input_date)
{
	std::map<std::string, std::string>::iterator it = _data.upper_bound(input_date);
	--it;
	return (it->first);
}
