#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <limits>

typedef struct s_pair
{
	int big;
	int small;
}	t_pair;

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();
		void exec(char **argv);
		// bool operator()(int a, int target)
		// {
		// 	_count++;
		// 	return (a < target);
		// }
	private:
		bool _validate_input(char **argv);
		void _create_deque(char **argv);
		void _create_vec(char **argv);
		std::vector<int> _sort(std::vector<int> vec);
		std::deque<int> _deq;
		std::vector<int> _vec;
		std::vector<int> _mekeOrderInsert(std::vector<int> jacob_seq, int size);
		std::vector<int> _makeJacobSeq(int n);
		std::vector<t_pair> _make_pairs(std::vector<int> vec);
		std::vector<t_pair> _make_sorted_pairs(std::vector<int> sorted,
									std::vector<t_pair> pairs,
									std::vector<int>& losers);
		std::vector<int>::iterator _search_insert_point(int pairs_big, std::vector<int>& sorted, int target);
		std::vector<int>& _insert_losers_to_sorted(std::vector<int>& sorted,
												std::vector<int>& losers,
												std::vector<t_pair>& sorted_pairs,
												std::vector<int>& order_insert);
		static bool comp(int a, int b);
		int _my_lower_bound(int start,
							int end,
							std::vector<int> sorted,
							int target);
		// int my_lower_bound(std::vector<int>::iterator begin,
		// 					std::vector<int>::iterator end,
		// 					int target);
		// static int _num_of_compare;
		// int _count;
};

// bool comp(int a, int b);

#endif
