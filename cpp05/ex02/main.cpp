#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// exception
	Bureaucrat bur("a", 0);
	Bureaucrat bur1("b", 151);

	// normal
	Bureaucrat bur2("c", 42);
	std::cout << bur2 << std::endl;

	Bureaucrat bur3("d", 9);
	std::cout << bur3 << std::endl;

	// ShrubberyCreationForm tests
	// AForm *scf = new ShrubberyCreationForm("aaaaa");

	ShrubberyCreationForm scf("SCF");
	try
	{
		std::cout << scf << std::endl;
		bur3.signForm(scf);
		bur3.executeForm(scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	AForm *rrf = new RobotomyRequestForm("bbbbb");
	AForm *ppf = new PresidentialPardonForm("cccc");
	try
	{
	bur3.executeForm(*rrf);
	bur3.executeForm(*ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
