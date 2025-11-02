#ifndef RPN_HPP
 #define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();
		void exec(std::string input);
	private:
		std::stack<std::string> _stack;
		bool validate_input(std::string input);
};

#endif
