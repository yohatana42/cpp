#include "iter.hpp"

int main()
{
	int array[] = {1, 2, 3};
	::iter(array, 3, func);

	const std::string str1 = "miss";
	std::string str[] = {"hellow", "world", "!", str1};
	::iter(str, 4, func);
	return (0);
}
