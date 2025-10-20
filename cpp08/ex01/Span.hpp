#ifndef SPAN_HPP
 #define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <stdlib.h>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span();
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	private:
		Span();
		std::vector<int> _vec;
		int _contents_count;
		int _contents_max;
};

#endif
