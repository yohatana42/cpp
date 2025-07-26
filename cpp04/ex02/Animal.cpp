#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	_type = src._type;
}

Animal& Animal::operator=(const Animal& src)
{
	_type = src._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "OOOOONNN" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}
