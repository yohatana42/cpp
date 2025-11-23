#include "PmergeMe.hpp"

int comparison_count = 0;

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
	std::cout << "比較回数 " << comparison_count << std::endl;
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

	seq.reserve(n);
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
		return (vec);

	std::vector<t_pair> pairs = _make_pairs(vec);

	// bigのみを取り出す
	int remainder = 0;
	std::vector<int> winners;
	for (int i = 0; i < (int)pairs.size();i++)
	{
		if (pairs[i].big != 0)
			winners.push_back(pairs[i].big);
		else
			remainder = pairs[i].small;
	}

	// ソートされた大の配列が帰ってくる
	std::vector<int> sorted = _sort(winners);

	// ここでソートされたbigのみの配列と最初に渡した配列の順番を合わせる
	// ソートしたbigにあわせてsmallの配列を並び替える
	std::vector<int> losers;
	std::vector<t_pair> sorted_pairs = _make_sorted_pairs(sorted, pairs, losers);
	if (remainder != 0)
		losers.push_back(remainder);

	// losers check
	// for (size_t i = 0; i < losers.size();i++)
	// {
	// 	std::cout << "losers " << losers[i] << std::endl;
	// }

	// ヤコブスタール配列の作成
	std::vector<int> jacob_array = _makeJacobSeq(size);

	// small配列の挿入順を決める
	std::vector<int> order_insert = _mekeOrderInsert(jacob_array, losers.size());

	// losersが全て挿入されるまでorder_insertの順番で入れる
	sorted = _insert_losers_to_sorted(sorted, losers, sorted_pairs, order_insert);

	// sorted check
	// std::cout << "-----------" << std::endl;
	// for (int i = 0; i < (int)sorted.size();i++)
	// {
	// 	std::cout << "i :" << i << " sorted :" << sorted[i] << std::endl;
	// }
	// std::cout << "-----------" << std::endl;
	return (sorted);
}

std::vector<t_pair> PmergeMe::_make_pairs(std::vector<int> vec)
{
	std::vector<t_pair> pairs;

	int size = vec.size();
	// 二個ずつの塊にする
	for (int i = 0; i < size; i = i + 2)
	{
		t_pair pair;
		if (i == size - 1)
		{
			pair.small = vec[i];
			pair.big = 0;
			pairs.push_back(pair);
		}
		else
		{
			if (vec[i] > vec[i + 1])
			{
				++comparison_count;
				pair.big = vec[i];
				pair.small = vec[i + 1];
			}
			else
			{
				++comparison_count;
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
	return (pairs);
}

std::vector<t_pair> PmergeMe::_make_sorted_pairs(std::vector<int> sorted,
									std::vector<t_pair> pairs,
									std::vector<int>& losers)
{
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
	return (sorted_pairs);
}

std::vector<int>::iterator PmergeMe::_search_insert_point(int pairs_big,
														std::vector<int>& sorted,
														int target)
{
	std::vector<int>::iterator insert_point;

	// ペアが存在しない場合は全探索する
	if (pairs_big == 0)
	{
		// insert_point =
		// std::lower_bound(sorted.begin(), sorted.end(), target);
		insert_point =
		std::lower_bound(sorted.begin(), sorted.end(), target, comp);
		// std::cout << "--- target ---" << target << std::endl;
		std::cout << "===== 比較回数 ===== " << insert_point - sorted.begin() << std::endl;
	}
	else
	{
		// ペアのbigをもとにsortedのbigのイテレータを取得
		std::vector<int>::iterator serch_end = std::find(sorted.begin(), sorted.end(), pairs_big);

		// sorted.begin()〜ペアのbigまでのイテレータまでを検索範囲とする
		// insert_point =
		// 	std::lower_bound(sorted.begin(), serch_end, target);
		insert_point =
			std::lower_bound(sorted.begin(), serch_end, target, comp);
	}

	return (insert_point);
}

std::vector<int>& PmergeMe::_insert_losers_to_sorted(std::vector<int>& sorted,
												std::vector<int>& losers,
												std::vector<t_pair>& sorted_pairs,
												std::vector<int>& order_insert)
{
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

		std::vector<int>::iterator insert_point =
			_search_insert_point(pairs_big, sorted, losers[order_insert[i]]);

		// bigの配列にsmallを挿入する
		sorted.insert(insert_point, losers[order_insert[i]]);
	}
	return (sorted);
}

bool PmergeMe::comp(int a, int target)
{
	std::cout << "==== comp! ====" << std::endl;
	std::cout << "a: " << a << " target: " << target << std::endl;
	++comparison_count;
	return a < target;
}

// bool comp(int a, int target)
// {
// 	std::cout << "==== comp! ====" << std::endl;
// 	std::cout << "a: " << a << " target: " << target << std::endl;
// 	// ここでカウントするのはわかる
// 	return a < target;
// }
