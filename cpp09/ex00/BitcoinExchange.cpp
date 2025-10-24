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
	_csv = read_data();
	if (!_csv)
	{
		std::cout << "open failed [data.csv]" << std::endl;
		return ;
	}
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
		validate_format(line);


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

std::fstream BitcoinExchange::read_data()
{
	std::fstream data;

	data.open("Data.csv");
	return (data);
}

bool BitcoinExchange::validate_format(std::string line)
{
	// split '|'
	// validate_date(line);
	return (true);
}

bool BitcoinExchange::validate_date(std::string date)
{
	int year;
	int month;
	int day;

	// 現在の年を取得する
	time_t t;
	t = time(NULL);
	tm *d = localtime(&t);


	// 年月日に分ける
	// 年が2007年以前、もしくは実行時の年以降なら弾く
}
