#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "cat constructor called" << std::endl;
}

Cat::Cat(const Cat& src)
{
	_type = src.getType();
}

Cat& Cat::operator=(const Cat& src)
{
	_type = src.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "nya~" << std::endl;
}
