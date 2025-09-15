#include "easyfind.hpp"
#include "easyfind.tpp"

int main()
{
	int sum = add(1, 2);
	std::cout << sum << std::endl;

	int result = 0;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	result = easyfind(v, 2);
	std::cout << "result :" << result << std::endl;
	return (0);
}
