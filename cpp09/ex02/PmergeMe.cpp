#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	(void)src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	(void)src;
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::exec(char **argv)
{
	if (!_validate_input(argv))
	{
		std::cerr << "Error" << std::endl;
		return ;
	}

	_create_deque(argv);
	_create_vec(argv);

	// std::vector<int> jacob_array;
	// jacob_array.reserve(argc - 1);
	// jacob_array = _makeJacobSeq(argc - 1);
	// _mekeOrderInsert(jacob_array);

	// std::cout << "====== jacob_array ======" << std::endl;
	// for (int i = 0; i < argc - 1; i++)
	// {
	// 	std::cout << "jacob :" << jacob_array[i] << std::endl;
	// }
	// std::cout << "============" << std::endl;

	// sort
	_sort(_vec);

	// print

	// dequeとvectorで秒数を比較すると違って嬉しいねーということらしい
	// <sys/time.h> の gettimeofday() を使う

}

bool PmergeMe::_validate_input(char **argv)
{
	for(int i = 1; argv[i] != NULL; i++)
	{
		for (int j =0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				return (false);
			}
		}
	}
	int n = 0;
	for (int i = 1; argv[i] != NULL; i++)
	{
		n = i + 1;
		while (argv[n] != '\0')
		{
			if (std::atoi(argv[i]) == std::atoi(argv[n]))
			{
				return (false);
			}
			++n;
		}
	}

	// TODO int_max < argv[i]の場合


	return (true);
}

void PmergeMe::_create_deque(char **argv)
{
	int i = 1;
	while (argv[i] != NULL)
	{
		_deq.push_back(std::atoi(argv[i]));
		i++;
	}
}

void PmergeMe::_create_vec(char **argv)
{
	int i = 1;
	while (argv[i] != NULL)
	{
		_vec.push_back(std::atoi(argv[i]));
		i++;
	}
}

std::vector<int> PmergeMe::_makeJacobSeq(int n)
{
	std::vector<int> seq;

	if (n <= 0)
		return (seq);
	seq.push_back(0);
	if (n == 1)
		return (seq);

	seq.push_back(1);
	for (int i = 2; i < n; ++i)
	{
		int next = seq[i - 1] + 2 * seq[i - 2];
		if (next > n)
			break;
		seq.push_back(next);
	}
	return (seq);
}

std::vector<int> PmergeMe::_mekeOrderInsert(std::vector<int> jacob_seq, int size)
{

	std::vector<int> order;
	std::vector<int>::iterator point = std::upper_bound(jacob_seq.begin(), jacob_seq.end(), size);
	size_t index = std::distance(jacob_seq.begin(), point);

	if (size == 0)
		return (order);
	if (size == 1)
	{
		order.push_back(0);
		return (order);
	}
	int i = 1;
	int start = 0;
	int end = 0;
	while (i < (int)index)
	{
		start = jacob_seq[i - 1] + 1;
		end = jacob_seq[i];
		while (start <= end)
		{
			order.push_back(end);
			--end;
		}
		i++;
	}

	return (order);
}

std::vector<int> PmergeMe::_sort(std::vector<int> vec)
{
	/*
		二個の要素をペア（構造体）にする
		（1個になるまで続ける）

		小の配列を大の配列に合わせる
		小を大の配列に挿入していく

		完成
	*/
	int size = vec.size();
	if (size == 1)
	{
		return (vec);
	}

	std::vector<t_pair> pairs;
	std::vector<int> winners;
	std::vector<int> losers;

	// 二個ずつの塊にする
	for (int i = 0; i < size; i = i + 2)
	{
		t_pair pair;
		if (i == size - 1)
		{
			// 余りはとっておく（smallに入れたい）
			pair.small = vec[i];
			pair.big = 0;
			// positive integerは０が入らないので0でよい
			pairs.push_back(pair);
		}
		else
		{
			if (vec[i] > vec[i + 1])
			{
				pair.big = vec[i];
				pair.small = vec[i + 1];
			}
			else
			{
				pair.big = vec[i + 1];
				pair.small = vec[i];
			}
			pairs.push_back(pair);
		}
	}
	// pairsチェック
	// for (int i = 0; i < (int)pairs.size();i++)
	// {
	// 	std::cout << "======" << std::endl;
	// 	std::cout << "big " << pairs[i].big << std::endl;
	// 	std::cout << "samll " << pairs[i].small << std::endl;
	// }

	// bigのみを取り出す
	for (int i = 0; i < (int)pairs.size();i++)
	{
		if (pairs[i].big != 0)
			winners.push_back(pairs[i].big);
	}

	std::cout << "======" << std::endl;
	for (int i = 0; i < (int)winners.size();i++)
	{
		std::cout << "winners " << winners[i] << std::endl;
	}
	std::cout << "======" << std::endl;

	std::vector<int> sorted;
	sorted = _sort(winners);
	// ↑これでソートされた大の配列が帰ってくる
	// ここでソートされたbigのみの配列と最初に渡した配列の順番を合わせる
	for (int i = 0; i < (int)pairs.size();i++)
	{
		// ソートされたbigをもとにうまいことやる
		// losers.push_back();
	}

	// ソートしたbigにあわせてsmallの配列を並び替える

	// small配列の挿入順を決める
	std::vector<int> jacob_array;
	std::vector<int> order_insert;
	jacob_array.reserve(size);
	jacob_array = _makeJacobSeq(size);

	// for (int i = 0;i< (int)jacob_array.size();i++)
	// {
	// 	std::cout << "jacob_array i:" << i << " content:" << jacob_array[i] << std::endl;
	// }

	order_insert = _mekeOrderInsert(jacob_array, losers.size());

	// for (int i = 0;i< (int)order_insert.size();i++)
	// {
	// 	std::cout << "order insert i:" << i << " content:" << order_insert[i] << std::endl;
	// }

	// bigの配列にsmallを挿入する
	// ヤコブスタール配列を二分探索の基準にする
	// upper_bound(挿入したい数値)にするといい感じの位置が取れる…？

	return (vec);
}

// ex00 めっちゃでかい数を入れてinfになればオッケー
