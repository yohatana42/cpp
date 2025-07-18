#ifndef FIXED_H
 #define FIXED_H

 #include <string>
 #include <iostream>
 #include <stdint.h>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& c);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		int toInt() const;
		float toFloat() const;
		
		Fixed operator--();
		Fixed operator--(int);
		Fixed operator++();
		Fixed operator++(int);
		
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
	private:
		int _fix_point;
		static const int _bit_count = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
