#include "Serializer.hpp"

int main()
{
	Data *data;
	Data *result_data;
	uintptr_t ptr;
	uintptr_t result_ptr;

	result_ptr = Serializer::serialize(data);
	result_data = Serializer::deserialize(ptr);
	return (0);
}
