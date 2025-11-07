#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <algorithm>

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
		std::vector<int> _sort(std::vector<int> vec);
		std::deque<int> _deq;
		std::vector<int> _vec;
		// void FordJohnsonSort(std::vector<int> vec);
		// void binaryInsert(std::vector<int> vec, int num);
		std::vector<int> _mekeOrderInsert(std::vector<int> jacob_seq, std::vector<int> losers);
		std::vector<int> _makeJacobSeq(int n);
};

#endif
