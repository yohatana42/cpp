#include "Array.hpp"

int main()
{
	Array<int> array(5);

	for (unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = i + 1;
	}

	for (unsigned int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << std::endl;
	}

	Array<int> copy = array;
	copy[0] = 999;
	if (array[0] != copy[0])
		std::cout << "copy ok" << std::endl;

	try
	{
		array[99] = 0;
	} catch (const std::exception& e)
	{
		std::cout << "OK" << std::endl;
	}

	return (0);
}
