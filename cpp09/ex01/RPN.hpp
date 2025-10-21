#ifndef RPN_HPP
 #define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();
};

#endif
