#include "Bureaucrat.hpp"

int main()
{
	// exception
	Bureaucrat bur("a", 0);
	Bureaucrat bur1("b", 151);

	// normal
	Bureaucrat bur2("c", 42);
	std::cout << bur2 << std::endl;
	return (0);
}
