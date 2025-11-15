#include "PmergeMe.hpp"

int main(int argc, char**argv)
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	else if (argc > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: too much argument" << std::endl;
		return (1);
	}

	PmergeMe merg;
	merg.exec(argv);
	return (0);
}
