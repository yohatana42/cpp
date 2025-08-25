#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// exception
	Bureaucrat bur("a", 0);
	Bureaucrat bur1("b", 151);

	// normal
	Bureaucrat bur2("c", 42);
	std::cout << bur2 << std::endl;

	Form form("form1", 10 ,20);
	std::cout << form << std::endl;

	bur2.signForm(form);

	return (0);
}
