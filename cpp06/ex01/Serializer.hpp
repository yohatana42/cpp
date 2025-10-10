#ifndef SERIALIZER_HPP
 #define SERIALIZER_HPP

//  #include <stdint.h>
 #include <iostream>
 #include <string>

typedef struct s_Data
{
	int num;
} Data;

class Serializer
{
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private :
		Serializer();
		Serializer(const Serializer& src);
		Serializer& operator=(const Serializer& src);
		~Serializer();
};

#endif
