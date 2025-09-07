#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat bur3("d", 1);
	std::cout << bur3 << std::endl;

	ShrubberyCreationForm scf("SCF");
	RobotomyRequestForm rrf("RRF");
	PresidentialPardonForm ppf("PPF");
	std::cout << "==== basic ====" << std::endl;
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

	ShrubberyCreationForm scf_e("scf_sign");
	RobotomyRequestForm rrf_e("rrf_sign");
	PresidentialPardonForm ppf_e("ppf_sign");

	std::cout << std::endl;
	std::cout << "==== signed error ====" << std::endl;
	// scf error
	Bureaucrat err_scf_sign("err_scf", 149);
	try
	{
		err_scf_sign.signForm(scf_e);
	}
	catch(const std::exception& e)
	{
		std::cout << err_scf_sign.getName() << " couldn't sign "
					<< scf_e.getName() << " because "
					<< e.what() << "." << std::endl;
	}

	Bureaucrat err_rff("err_rrf", 73);
	try
	{
		err_rff.signForm(rrf_e);
	}
	catch(const std::exception& e)
	{
		std::cout << err_rff.getName() << " couldn't sign "
					<< rrf_e.getName() << " because "
					<< e.what() << "." << std::endl;
	}

	Bureaucrat err_ppf("err_ppf", 26);
	try
	{
		err_ppf.signForm(ppf_e);
	}
	catch(const std::exception& e)
	{
		std::cout << err_ppf.getName() << " couldn't sign "
					<< ppf_e.getName() << " because "
					<< e.what() << "." << std::endl;
	}

	// execute error
	std::cout << std::endl;
	std::cout << "==== execute error ====" << std::endl;
	Bureaucrat test1("test1", 140);
	ShrubberyCreationForm scf_exec("scf_exec");

	try
	{
		test1.signForm(scf_exec);
		test1.executeForm(scf_exec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat test2("test2", 60);
	RobotomyRequestForm rrf_exec("rrf_exec");
	try
	{
		test2.signForm(rrf_exec);
		test2.executeForm(rrf_exec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat test3("test3", 10);
	PresidentialPardonForm ppf_exec("ppf_exec");
	try
	{
		test3.signForm(ppf_exec);
		test3.executeForm(ppf_exec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat test4("test4", 20);
	ShrubberyCreationForm scf_nosign("nosign");
	try
	{
		test4.executeForm(scf_nosign);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
