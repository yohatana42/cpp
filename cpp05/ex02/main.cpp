#include "Bureaucrat.hpp"
#include "Form.hpp"
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

	AForm *scf = new ShrubberyCreationForm("");
	AForm *rrf = new RobotomyRequestForm("");
	AForm *ppf = new PresidentialPardonForm("");
	bur3.executeForm(*scf);

	return (0);
}
