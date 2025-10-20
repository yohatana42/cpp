#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		// exception
		sp.addNumber(21);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span span = Span(10000);
	for (int i = 0; i < 10000; i++)
		span.addNumber(i);
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;


	std::vector<int> v;
	for (int i = 0; i < 7; i ++)
	{
		v.push_back(i);
	}
	Span s(7);
	s.addNumbers(v.begin(), v.end());
	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl;


	return (0);
}
