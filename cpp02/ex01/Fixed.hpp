#ifndef FIXED_H
 #define FIXED_H

 #include <string>
 #include <iostream>

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
	private:
		int _fix_point;
		static const int _bit_count = 8;
};

// ostreamはFixed classに依存していないのでここに記載
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
