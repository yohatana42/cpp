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


	// 計測開始
	_create_vec(argv);
	std::vector<int> sorted = _sort(_vec);
	// 計測終了

	// print
	std::cout << "========= result ===========" << std::endl;
	for (int i = 0; i < (int)sorted.size();i++)
	{
		std::cout << sorted[i] << " ";
		if (i == (int)sorted.size() - 1)
			std::cout << std::endl;
	}

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
		if (std::atoi(argv[i]) == 0)
			{
				return (false);
			}
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

	if (size == 0)
		return (order);
	if (size == 1)
	{
		order.push_back(0);
		return (order);
	}

	size_t j = 0;
	while (j < jacob_seq.size())
	{
		int x = jacob_seq[j];
		if (x == 0)
		{
			order.push_back(0);
			j++;
			continue ;
		}

		int s = size - 1;
		for (int k = x; k > jacob_seq[j - 1] && (int)order.size() < size; --k)
		{
			if (size <= jacob_seq[j] && s > jacob_seq[j - 1])
			{
				order.push_back(s);
				s--;
			}
			else
			{
				order.push_back(k);
			}
		}
		j++;
	}
	return (order);
}

std::vector<int> PmergeMe::_sort(std::vector<int> vec)
{
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
	// pairs check
	// for (int i = 0; i < (int)pairs.size();i++)
	// {
	// 	std::cout << "======" << std::endl;
	// 	std::cout << "big " << pairs[i].big << std::endl;
	// 	std::cout << "samll " << pairs[i].small << std::endl;
	// }
	// std::cout << "======" << std::endl;

	int remainder = 0;
	// bigのみを取り出す
	for (int i = 0; i < (int)pairs.size();i++)
	{
		if (pairs[i].big != 0)
			winners.push_back(pairs[i].big);
		else
		{
			remainder = pairs[i].small;
		}
	}

	// ソートされた大の配列が帰ってくる
	std::vector<int> sorted;
	sorted = _sort(winners);

	// sorted check
	// std::cout << "-----------" << std::endl;
	// for (int i = 0; i < (int)sorted.size();i++)
	// {
	// 	std::cout << "i :" << i << " sorted :" << sorted[i] << std::endl;
	// }
	// std::cout << "-----------" << std::endl;


	// ここでソートされたbigのみの配列と最初に渡した配列の順番を合わせる
	// ソートしたbigにあわせてsmallの配列を並び替える
	std::vector<t_pair> sorted_pairs;
	int j;
	for (int i = 0; i < (int)sorted.size();i++)
	{
		j = 0;
		while (j < (int)pairs.size())
		{
			if (sorted[i] == pairs[j].big)
			{
				sorted_pairs.push_back(pairs[j]);
				losers.push_back(pairs[j].small);

				// check
				// std::cout << "big " << pairs[j].big << std::endl;
				// std::cout << "small " << pairs[j].small << std::endl;
			}
			j++;
		}
	}
	if (remainder != 0)
		losers.push_back(remainder);

	// losers check
	// for (size_t i = 0; i < losers.size();i++)
	// {
	// 	std::cout << "losers " << losers[i] << std::endl;
	// }

	// ヤコブスタール配列の作成
	std::vector<int> jacob_array;
	std::vector<int> order_insert;
	jacob_array.reserve(size);
	jacob_array = _makeJacobSeq(size);

	// small配列の挿入順を決める
	order_insert = _mekeOrderInsert(jacob_array, losers.size());

	for (int i = 0;i< (int)order_insert.size();i++)
	{
		// std::cout << "order insert i:" << i << " content:" << order_insert[i] << std::endl;
	}

	// losersが全て挿入されるまで続く
	// order_insertの順番で入れる
	for (size_t i = 0; i < losers.size(); i++)
	{
		// std::cout << "i " << i << " losers[i] " << losers[i] << " losers[order_insert[i]] "<< losers[order_insert[i]]<< std::endl;
		int pairs_big = 0;
		// losers[order_insert[i]]のペアのbigを探す
		for (size_t j = 0; j < sorted_pairs.size(); j++)
		{
			// std::cout << "j " << j << std::endl;
			if (losers[order_insert[i]] == sorted_pairs[j].small)
			{
				pairs_big = sorted_pairs[j].big;
				// std::cout << "pairs_big " << pairs_big << std::endl;
			}
		}

		std::vector<int>::iterator insert_point;
		// ペアが存在しない場合は全探索する
		if (pairs_big == 0)
		{
			// std::cout << "order_insert[i] " << order_insert[i] << std::endl;
			insert_point =
			std::lower_bound(sorted.begin(), sorted.end(), losers[order_insert[i]]);
		}
		else
		{
			// コレ二分探索になるのか・・・？
			// ペアのbigをもとにsortedのbigのイテレータを取得
			std::vector<int>::iterator serch_end = std::find(sorted.begin(), sorted.end(), pairs_big);

			// sorted.begin()〜ペアのbigまでのイテレータまでを検索範囲とする
			insert_point =
				std::lower_bound(sorted.begin(), serch_end, losers[order_insert[i]]);
		}

		// bigの配列にsmallを挿入する
		sorted.insert(insert_point, losers[order_insert[i]]);
	}

	return (sorted);
}
