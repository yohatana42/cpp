#include "PmergeMe.hpp"

int main(int argc, char**argv)
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	PmergeMe merg;
	merg.exec(argv);
	return (0);
}
