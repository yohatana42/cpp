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
		seq.push_back(next);
	}
	return (seq);
}

// 配列の数　< ヤコブスタール配列になるようにしたい
// ヤコブスタール配列は1, 3, 5, 11, 21...と続く
// [1, 3, 2, 4, 6 ,5]という配列があった場合、
//  1  3  2  5  4  6の順番で挿入していく（らしい）
// この挿入するインデックスの順番を返したい（この場合は0,2,1,4,3,5の配列になる）
std::vector<int> PmergeMe::_mekeOrderInsert(std::vector<int> jacob_seq, std::vector<int> losers)
{
	(void)jacob_seq;
	(void)losers;

	std::vector<int> order;
	// 挿入する配列の長さが必要
	std::vector<int>::iterator point = std::upper_bound(jacob_seq.begin(), jacob_seq.end(), losers.size());

	std::cout << "losers.size() :" << losers.size() << std::endl;
	std::cout << "point "<< *point << std::endl;
	size_t index = std::distance(jacob_seq.begin(), point);
	std::cout << "index :" << index << " jacob_seq :"<< jacob_seq[index] << std::endl;

	// push_back(index)したい
	for (int i = 0; (int)i < losers.size();i++)
	{
		// うまく入るのか？これ
	}

	return (order);
}


// ヤコブスタール配列を作る
// ヤコブスタール配列に沿ってオーダー順を決める
// （探索範囲を決める）

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

	std::vector<t_pair> winners;
	std::vector<int> losers;

	// 二個ずつの塊にする
	for (int i = 0; i < size; i = i + 2)
	{
		t_pair pair;
		if (i == size - 1)
		{
			// 余りはとっておく（smallに入れたい）
			pair.small = vec[i];
			// bigを0にすると問題がありそうなので考えるべき
			winners.push_back(pair);
		}
		else
		{
			pair.big = vec[i];
			pair.small = vec[i + 1];
			winners.push_back(pair);
		}
	}

	// bigのみを取り出す
	// _sort(bigs_array)
	// ↑これでソートされた大の配列が帰ってくる（多分）

	// bigのみソートする
	// ソートしたbigにあわせてsmallの配列を並び替える

	losers.push_back(9);
	losers.push_back(7);
	losers.push_back(2);
	losers.push_back(1);
	losers.push_back(3);
	losers.push_back(8);

	// small配列の挿入順を決める
	std::vector<int> jacob_array;
	jacob_array.reserve(size);
	jacob_array = _makeJacobSeq(size);
	_mekeOrderInsert(jacob_array, losers);

	// bigの配列にsmallを挿入する
	// ヤコブスタール配列を二分探索の基準にする
	// upper_bound(挿入したい数値)にするといい感じの位置が取れる…？

	return (vec);
}
