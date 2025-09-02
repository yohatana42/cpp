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

	Bureaucrat bur3("d", 1);
	std::cout << bur3 << std::endl;

	ShrubberyCreationForm scf("SCF");
	RobotomyRequestForm rrf("RRF");
	PresidentialPardonForm ppf("PPF");
	try
	{
		bur3.signForm(scf);
		bur3.executeForm(scf);
		bur3.signForm(rrf);
		bur3.executeForm(rrf);
		bur3.signForm(ppf);
		bur3.executeForm(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	ShrubberyCreationForm scf_e("scf_e");
	RobotomyRequestForm rrf_e("rrf_e");
	PresidentialPardonForm ppf_e("ppf_e");

	// scf error
	Bureaucrat err_scf_sign("err_scf", 138);
	try
	{
		err_scf_sign.signForm(scf_e);
		err_scf_sign.executeForm(scf_e);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat err_rff("err_rrf", 46);
	try
	{
		err_rff.signForm(rrf_e);
		err_rff.executeForm(rrf_e);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat err_ppf("err_ppf", 6);
	try
	{
		err_ppf.signForm(ppf_e);
		err_ppf.executeForm(ppf_e);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
