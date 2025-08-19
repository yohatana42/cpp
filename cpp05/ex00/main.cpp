#include "Bureaucrat.hpp"

int main()
{
	// exception
	Bureaucrat bur("a", 0);
	Bureaucrat bur1("b", 151);

	// normal
	Bureaucrat bur2("c", 42);
	std::cout << bur2 << std::endl;

	Bureaucrat bur3("d", 1);
	std::cout << bur3 << std::endl;
	bur3.remove_grade();

	Bureaucrat bur4("e", 150);
	std::cout << bur4 << std::endl;
	bur4.add_grade();

	return (0);
}
