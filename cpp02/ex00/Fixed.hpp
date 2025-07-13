#ifndef FIXED_H
 #define FIXED_H

 #include <string>
 #include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& c);
		int getRawBits();
		void setRawBits(int const raw);
	private:
		int _fix_point;
		static const int _bit_count = 8;
};

#endif
