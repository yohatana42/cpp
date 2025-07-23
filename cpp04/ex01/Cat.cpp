#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "cat constructor called" << std::endl;
}

Cat::Cat(const Cat& src)
{
	_type = src.getType();
	for (int i = 0;i < 100; i++)
		_brain->_ideas[i] = src.getBrain()->_ideas[i];
}

Cat& Cat::operator=(const Cat& src)
{
	_type = src.getType();
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
