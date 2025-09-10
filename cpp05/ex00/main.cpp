#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== normal ===" << std::endl;
	try
	{
		Bureaucrat bur2("c", 42);
		std::cout << bur2 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=== exception ===" << std::endl;
	try
	{
		Bureaucrat bur("a", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat bur1("b", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		Bureaucrat bur3("d", 1);
		std::cout << bur3 << std::endl;
		bur3.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat bur4("e", 150);
		std::cout << bur4 << std::endl;
		bur4.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
