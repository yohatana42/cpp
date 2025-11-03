#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

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
		std::deque<int> _deq;
		std::vector<int> _vec;
};

#endif
