#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <sys/time.h>

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
	private:
		bool _validate_input(char **argv);
		void _create_deque(char **argv);
		void _create_vec(char **argv);

		// vector
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

		// deque
		std::deque<int> _sort_deq(std::deque<int> deq);
		std::deque<int> _mekeOrderInsert_deq(std::deque<int> jacob_deq, int size);
		std::deque<int> _makeJacobSeq_deq(int n);
		std::deque<t_pair> _make_pairs_deq(std::deque<int> vec);
		std::deque<t_pair> _make_sorted_pairs_deq(std::deque<int> sorted,
									std::deque<t_pair> pairs,
									std::deque<int>& losers);
		std::deque<int>::iterator _search_insert_point_deq(int pairs_big, std::deque<int>& sorted, int target);
		std::deque<int>& _insert_losers_to_sorted_deq(std::deque<int>& sorted,
												std::deque<int>& losers,
												std::deque<t_pair>& sorted_pairs,
												std::deque<int>& order_insert);
		int _my_lower_bound_deq(int start,
							int end,
							std::deque<int> sorted,
							int target);
		static const int _print_max = 25;
};

#endif
