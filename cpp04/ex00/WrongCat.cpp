#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "Cat";
	std::cout << "wrong cat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
	_type = src.getType();
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	_type = src.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "wrong cat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "nya" << std::endl;
}
