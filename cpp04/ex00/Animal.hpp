#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		~Animal();
		void makeSound();
		std::string getType();
	protected:
		std::string _type;
};

#endif
