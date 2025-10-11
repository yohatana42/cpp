#include "Serializer.hpp"

int main()
{
	Data data;
	data.num = 150;
	Data *result_data = NULL;
	uintptr_t result_ptr = 0;

	result_ptr = Serializer::serialize(&data);
	result_data = Serializer::deserialize(result_ptr);
	std::cout << "origin:" << &data << std::endl;
	std::cout << "copy  :" <<result_data << std::endl;
	if (&data == result_data)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "NG" << std::endl;
	}
	return (0);
}
