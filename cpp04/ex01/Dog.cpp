#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "dog constructor called" << std::endl;
}

Dog::Dog(const Dog& src)
{
	_type = src.getType();
}

Dog& Dog::operator=(const Dog& src)
{
	_type = src.getType();
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "wan" << std::endl;
}
