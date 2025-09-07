#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm *noexist;
	Bureaucrat bur("Bureaucrat", 1);

	rrf = intern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		bur.signForm(*rrf);
		bur.executeForm(*rrf);
	}

	ppf = intern.makeForm("presidential pardon", "nusu");
	if (ppf)
	{
		bur.signForm(*ppf);
		bur.executeForm(*ppf);
	}

	scf = intern.makeForm("shrubbery creation", "uuuu");
	if (scf)
	{
		bur.signForm(*scf);
		bur.executeForm(*scf);
	}

	noexist = intern.makeForm("none", "null");
	if (noexist == NULL)
		std::cout << "no exist fome name" << std::endl;

	delete(rrf);
	delete(ppf);
	delete(scf);
	return (0);
}
