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
		std::cout << line << std::endl;
		if (!validate_format(line))
			continue ;
		++i;
	}
	stream.close();

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
	while (std::getline(stream, line))
	{
		if (i == 0)
			continue ;
		split_pos = line.find(",");
		_data.insert(std::make_pair(line.substr(0, split_pos)
									,line.substr(split_pos + 1, line.size())));
		++i;
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
	std::string year;
	std::string month;
	std::string day;

	// -で区切る
	int left_split_pos = date.find("-");
	int right_split_pos = date.rfind("-");

	year = date.substr(0, left_split_pos);
	month = date.substr(left_split_pos, right_split_pos);
	day = date.substr(right_split_pos, date.size());

	// 年がcsvデータの一番最初の日付よりも前か、実行時の年以降なら弾く
	// csvの一番最初のデータはイテレーターのstartで取れる　多分

	// 月の範囲が１〜１２であること
	// 日付の範囲が月に沿った範囲であること


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
	// // 現在の年を取得する
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
