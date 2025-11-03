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
	// create_vector()

	// sort

	// print

	// dequeとvectorで秒数を比較すると違って嬉しいねーということらしい
	// <sys/time.h> の gettimeofday() を使う

	// 純粋なマージソートをやってみる

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
	// うまいこと入れる
}
