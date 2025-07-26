#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& src)
{
	_type = src.getType();
	// deep copy
	_brain = new Brain(*src.getBrain());
}

Cat& Cat::operator=(const Cat& src)
{
	_type = src.getType();
	_brain = new Brain(*src.getBrain());
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "nya~" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (_brain);
}
