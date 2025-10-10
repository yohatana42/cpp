#include "Serializer.hpp"

int main()
{
	Data *data = NULL;
	Data *result_data = NULL;
	uintptr_t ptr = 1;
	uintptr_t result_ptr = 0;

	result_ptr = Serializer::serialize(data);
	result_data = Serializer::deserialize(ptr);
	std::cout << result_ptr << std::endl;
	std::cout << result_data << std::endl;
	return (0);
}
