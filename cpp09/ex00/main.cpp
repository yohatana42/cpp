#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "invalid argument" << std::endl;
		return (1);
	}

	BitcoinExchange change;
	change.exec(argv[1]);

	return (0);
}
