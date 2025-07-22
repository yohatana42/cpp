#include "Fixed.hpp"

int main()
{
	Fixed a;

	std::cout << "=== increment ===" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "=== decrement ===" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << "=== arithmetic operators ===" << std::endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	// 実装したやつ全部書いとく
	if (c < b)
		std::cout << "c < b" << std::endl;
	else
		std::cout << "c > b" << std::endl;
	if (c > b)
		std::cout << "c > b" << std::endl;
	else
		std::cout << "c < b" << std::endl;
	if (c >= b)
		std::cout << "c >= b" << std::endl;
	else
		std::cout << "c < b" << std::endl;
	if (c <= b)
		std::cout << "c < b" << std::endl;
	else
		std::cout << "c > b" << std::endl;

	if (c == b)
		std::cout << "c is b" << std::endl;
	else
		std::cout << "c is NOT b" << std::endl;
	if (c != b)
		std::cout << "c is NOT b" << std::endl;
	else
		std::cout << "c is b" << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	return 0;
}
