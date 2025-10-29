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
	// _csv = read_data();
	// if (!_csv)
	// {
	// 	std::cout << "open failed [data.csv]" << std::endl;
	// 	return ;
	// }


	if (!validate_input(filename))
		return ;


	std::fstream stream;
	stream.open(filename.c_str());
	if (!stream)
	{
		std::cout << "file open failed!" << std::endl;
		return ;
	}

	std::string line;
	while (std::getline(stream, line))
	{
		std::cout << line << std::endl;
		if (!validate_format(line))
		{
			continue ;
		}


	}
	stream.close();
	_csv.close();

	// 存在しない日付は一番近い前の日付にする
	// ただしビットコインの誕生が2008年とかそのへんなのでそれ以前は弾く
	// 明日（実行時の）を入力された場合も弾く

	// 入力ファイルを読み取る
		// 入力ファイルが存在しない、読み取れない場合エラー出力して終了

	// 一行ずつ処理
		// パイプで区切る
			// パイプが存在しない場合はエラー出力して次の行
			// 数値がintの正の数に収まらない場合、エラー出力して次の行

		// 日付でdatabase内部の検索
			// カレンダーに存在する日付かどうかチェックする（9999/99/99とかうるう年とか）
			// 存在する日付はそのまま為替値を取得
			// 存在しない場合は一番近い日付（未来に寄せる？）を取得

		// 掛け算する
		// 出力する
}

bool BitcoinExchange::validate_input(std::string filename)
{
	std::fstream s;

	s.open(filename.c_str());
	if (!s)
	{
		std::cout << "file open failed!" << std::endl;
		return (false);
	}
	s.close();
	return (true);
}

// mapを返してcloseしたほうが良い
// std::fstream BitcoinExchange::read_data()
// {
// 	std::fstream data;

// 	data.open("Data.csv");
// 	return (data);
// }

bool BitcoinExchange::validate_format(std::string line)
{
	// split '|'
	int pipe_pos = line.find("|");
	int pipe_pos2 = line.rfind("|");
	if (pipe_pos == (int)std::string::npos || pipe_pos != pipe_pos2)
	{
		std::cout << "Error: bad input => " << line<< std::endl;
		return (false);
	}

	trim_space(line);

	std::string date;
	std::string value;
	date = line.substr(0, pipe_pos - 1);
	value = line.substr(pipe_pos, line.size());

	if (!validate_date(date))
		return (false);
	if (!validate_value(value))
		return (false);
	return (true);
}

bool BitcoinExchange::validate_date(std::string date)
{
	(void)date;
	// int year;
	// int month;
	// int day;

	// // 現在の年を取得する
	// time_t t;
	// t = time(NULL);
	// tm *d = localtime(&t);


	// 年月日に分ける
	// 年が2007年以前、もしくは実行時の年以降なら弾く
	return (true);
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
	if (std::numeric_limits<int>::max() < val)
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
