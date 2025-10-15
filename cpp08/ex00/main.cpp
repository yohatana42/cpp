#include "easyfind.hpp"

int main()
{
	std::vector<int>::iterator result;
	std::vector<int> v;

	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	try
	{
		result = ::easyfind(v, 2);
		std::cout << "result :" << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::list<int>::iterator result2;
	std::list<int> list;
	list.push_back(1);
	list.push_back(1);
	list.push_back(1);
	try
	{
		result2 = ::easyfind(list, 2);
		std::cout << "result :" << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
