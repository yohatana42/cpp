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

	makeJacobSeq(21);

	// sort
	_sort(_vec);

	// print

	// dequeとvectorで秒数を比較すると違って嬉しいねーということらしい
	// <sys/time.h> の gettimeofday() を使う

}

bool PmergeMe::_validate_input(char **argv)
{
	// 正の数のみを受け付ける
	// 文字種類チェック
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
	// 重複チェック
	int n = 0;
	for (int i = 1; argv[i] != NULL; i++)
	{
		n = i + 1;
		while (argv[n + 1])
		{
			if (argv[i] == argv[n])
				return (true);
			++n;
		}
	}
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

void PmergeMe::FordJohnsonSort(std::vector<int> vec)
{
	std::vector<int> winners;
	std::vector<int> losers;

	int n = vec.size();
	if (n <= 1)
		return ;
	if (n % 2 == 1)
	{
		int extra = vec[vec.size() - 1];
		vec.pop_back();
		FordJohnsonSort(vec);
		binaryInsert(vec, extra);
		return ;
	}

	int specialLoser;
	if (vec[0] < vec[1])
	{
		winners.push_back(vec[1]);
		specialLoser = vec[0];
	}
	else
	{
		winners.push_back(vec[0]);
		specialLoser = vec[1];
	}

	// for (int i = 0;)
	// {

	// }
}

std::vector<int> PmergeMe::makeJacobSeq(int n)
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
std::vector<int> PmergeMe::mekeOrderInsert(std::vector<int> jacob_seq)
{
	std::vector<int> seq;
	return (seq);
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
	// 2こずつの塊にする

	// bigのみソートする
	// ソートしたbigにあわせてsmallの配列を並び替える

	// bigの配列にsmallを挿入する
	// ヤコブスタール配列を二分探索の基準にする

	return (vec);
}
