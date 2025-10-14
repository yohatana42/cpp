#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "invalid argument" << std::endl;
		return (1);
	}

	std::string str = argv[1];
	ScalarConverter::convert(str);

	return (0);
}
/*
// test patern
1 ok
42 ok
200 ok
a ok
z ok
A ok
Z ok
-1 ok
-200 ok
0 ok
0.0 ok
1f ok
5.27136f ok
42.198467 ok
0.1732783 ok

// error
ab ok
123s122 ok
4222222222222222222222222222222222222222222222222222.0000000000000000000


*/

