#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fix_point = 0;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fix_point = src.getRawBits();
}

// コピー代入演算子
Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fix_point = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return (_fix_point);
}

void Fixed::setRawBits(int const raw)
{
	_fix_point = raw;
}

// Default constructor called

// Copy constructor called
// Copy assignment operator called // <-- This line may be missing depending on your implementation
// getRawBits member function called

// Default constructor called

// Copy assignment operator called
// getRawBits member function called

// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0

// Destructor called
// Destructor called
// Destructor called
