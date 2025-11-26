#include "PmergeMe.hpp"

int comparison_count = 0;
int pairs_count = 0;
int insert_count = 0;

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

	std::cout << "input ";
	for (int i =1; argv[i] !=NULL; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	// 計測開始
	_create_vec(argv);
	std::vector<int> sorted = _sort(_vec);
	// 計測終了

	// print
	std::cout << "========= result ===========" << std::endl;
	std::cout << "比較回数 " << comparison_count << std::endl;
	// std::cout << "ペアの比較回数" << pairs_count << std::endl;
	// std::cout << "lower_boundの呼び出し回数" << insert_count << std::endl;
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

	// std::cout << "_mekeOrderInsert size " << size << std::endl;

	if (size == 0)
		return (order);
	if (size == 1)
	{
		order.push_back(0);
		return (order);
	}

	size_t j = 1;
	int begin = 0;
	while (j < jacob_seq.size())
	{
		// ブロックの範囲を決める
		// 1 [2 3] [4 5] [6 7 ... 11]...
		int end = jacob_seq[j];
		// std::cout << "j " << j;
		// std::cout << " end " << end << std::endl;

		if (size < end)
		{
			break ;
		}

		while (begin < end)
		{
			// std::cout << "order push_back is " << end -1<< std::endl;
			order.push_back(end - 1);
			--end;
		}
		begin = jacob_seq[j];
		j++;
	}
	while (jacob_seq[j -1] < size)
	{
		order.push_back(size - 1);
		--size;
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

	// ソートしたbigにあわせてsmallの配列を並び替える
	std::vector<int> losers;
	std::vector<t_pair> sorted_pairs = _make_sorted_pairs(sorted, pairs, losers);
	if (remainder != 0)
		losers.push_back(remainder);

	// ヤコブスタール配列の作成
	std::vector<int> jacob_array = _makeJacobSeq(size);

	// small配列の挿入順を決める
	std::vector<int> order_insert = _mekeOrderInsert(jacob_array, losers.size());

	// losersが全て挿入されるまでorder_insertの順番で入れる
	sorted = _insert_losers_to_sorted(sorted, losers, sorted_pairs, order_insert);
	return (sorted);
}

std::vector<t_pair> PmergeMe::_make_pairs(std::vector<int> vec)
{
	std::vector<t_pair> pairs;

	int size = vec.size();
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
			++comparison_count;
			++pairs_count;
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
			}
			j++;
		}
	}

	// std::cout << "-- losers --" << std::endl;
	// for (size_t i = 0; i < losers.size(); i++)
	// {
	// 	std::cout << losers[i] << " ";
	// }
	// std::cout << std::endl;

	return (sorted_pairs);
}

std::vector<int>::iterator PmergeMe::_search_insert_point(int pairs_big,
														std::vector<int>& sorted,
														int target)
{
	std::vector<int>::iterator insert_point;

	// ペアが存在しない場合は全探索する
	int index = 0;
	if (pairs_big == 0)
	{
		// 二分探索を自力で書く
		// insert_point =
		// _my_lower_bound(sorted.begin(), sorted.end(), target);
		index =
			_my_lower_bound(0, sorted.size() -1, sorted, target);

		// insert_point =
		// std::lower_bound(sorted.begin(), sorted.end(), target, comp);
	}
	else
	{
		// ペアのbigをもとにsortedのbigのイテレータを取得
		std::vector<int>::iterator serch_end = std::find(sorted.begin(), sorted.end(), pairs_big);

		// std::cout << pairs_big << " " << *serch_end << std::endl;

		int end = std::distance(sorted.begin(), serch_end);
		// sorted.begin()〜ペアのbigまでのイテレータまでを検索範囲とする
		index =
			_my_lower_bound(0, end -1, sorted, target);

			// insert_point =
			// 	std::lower_bound(sorted.begin(), serch_end -1, target, comp);
		}
	insert_point = sorted.begin() + index;
	return (insert_point);
}

std::vector<int>& PmergeMe::_insert_losers_to_sorted(std::vector<int>& sorted,
												std::vector<int>& losers,
												std::vector<t_pair>& sorted_pairs,
												std::vector<int>& order_insert)
{
	for (size_t i = 0; i < losers.size(); i++)
	{

		// std::cout << "order_insert :";
		// for (size_t k = 0; k < order_insert.size();k++)
		// {
		// 	std::cout << order_insert[k] << " ";
		// }
		// std::cout << std::endl;

		// if (i == 0)
		// {
		// 	sorted.insert(sorted.begin(), losers[order_insert[i]]);
		// 	continue ;
		// }

		int pairs_big = 0;
		// losers[order_insert[i]]のペアのbigを探す
		for (size_t j = 0; j < sorted_pairs.size(); j++)
		{
			if (losers[order_insert[i]] == sorted_pairs[j].small)
			{
				pairs_big = sorted_pairs[j].big;
			}
		}
		std::cout << "===== pairs_big " << pairs_big << std::endl;
		for (size_t j = 0; j < sorted.size(); j++)
		{
			std::cout << sorted[j];
		}
		std::cout << std::endl;

		std::vector<int>::iterator insert_point =
				_search_insert_point(pairs_big, sorted, losers[order_insert[i]]);

		// bigの配列にsmallを挿入する
		sorted.insert(insert_point, losers[order_insert[i]]);
	}
	return (sorted);
}

bool PmergeMe::comp(int a, int target)
{
	++comparison_count;
	++insert_count;
	return a < target;
}

int PmergeMe::_my_lower_bound(int begin,
							int end,
							std::vector<int> sorted,
							int target)
{

	std::cout << "~~~ _my_lower_bound ~~~" << std::endl;
	std::cout << "target " << target << std::endl;
	// コレを二分探索にしよう！
	// 真ん中を決める
	// なんかこいつおかしいな　1個の条件で決まってる気配ある

	std::cout << "begin " << begin << " end " << end << std::endl;
	int left = begin - 1;
	int right = end + 1;
	int mid;
	while (right - left > 1)
	{
		std::cout << "left " << left << " right " << right << std::endl;
		mid = left + (right - left) / 2;
		std::cout << "mid " << mid << " "<<sorted[mid] << " "<< target <<std::endl;
		++comparison_count;
		if (sorted[mid] < target)
			left = mid;
		else
			right = mid;
	}
	std::cout << "right " << right  << " left " << left<< std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~" << std::endl;
	return (right);
}
