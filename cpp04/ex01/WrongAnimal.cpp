#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "animal";
	std::cout << "wrong animal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	_type = src.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	_type = src.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "wrong animal destructor" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "UUUOONNN" << std::endl;
}
