#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "dog constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& src)
{
	_type = src.getType();
	_brain = new Brain(*src.getBrain());
	// for (int i = 0;i < 100; i++)
	// 	_brain->set_ideas(src.getBrain()->get_ideas());
}

Dog& Dog::operator=(const Dog& src)
{
	_type = src.getType();
	_brain = new Brain(*src.getBrain());
	// for (int i = 0;i < 100; i++)
	// 	_brain->set_ideas(src.getBrain()->get_ideas());
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

Brain* Dog::getBrain() const
{
	return (_brain);
}
