#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <string>
#include <iostream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();
	private:
};

#endif
