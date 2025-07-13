#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	_fix_point = src._fix_point;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	Fixed& fix_ref = src;
 	std::cout << "Copy assignment operator called" << std::endl;
	return (fix_ref);
}

int Fixed::getRawBits()
{
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
