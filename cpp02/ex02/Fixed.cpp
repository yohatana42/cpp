#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fix_point = 0;
}

Fixed::Fixed(const int num)
{
	int temp = num;
	
	temp <<= 8;
	_fix_point = temp;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	_fix_point = static_cast<int>(num * static_cast<float>(1 << 8) + 0.5f);
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fix_point = src.getRawBits();
}

// コピー代入演算子
Fixed& Fixed::operator=(const Fixed& src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fix_point = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (_fix_point);
}

void Fixed::setRawBits(int const raw)
{
	_fix_point = raw;
}

int Fixed::toInt() const
{
	int num = _fix_point;
	num >>= 8;
	return (num);
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_fix_point) / static_cast<float>(1 << 8));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed Fixed::operator--()
{
	this->_fix_point--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fix_point--;
	return (temp);
}

Fixed Fixed::operator++()
{
	this->_fix_point++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fix_point++;
	return (temp);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	int64_t temp = this->_fix_point + other._fix_point;
	result.setRawBits(static_cast<int>(temp >> 8));
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	int temp = this->_fix_point - other._fix_point;
	result.setRawBits(temp >> 8);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;

	int64_t temp = this->_fix_point * other._fix_point;
	result.setRawBits(static_cast<int>(temp >> 8));
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const 
{
	Fixed result;

	int temp = this->_fix_point / other._fix_point;
	result.setRawBits(temp >> 8);
	return (result);
}

bool Fixed::operator>(const Fixed& other) const
{
	if (this->_fix_point > other._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->_fix_point >= other._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->_fix_point < other._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->_fix_point <= other._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
	if (this->_fix_point == other._fix_point)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (this->_fix_point != other._fix_point)
		return (true);
	return (false);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
