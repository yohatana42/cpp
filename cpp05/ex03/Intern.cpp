# include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	func["presidential pardon"] = &createPresidentialPardonForm;
	func["robotomy request"] = &createRobotomyRequestForm;
	func["shrubbery creation"] = &createShrubberyCreationForm;

	std::map<std::string, _formFunc>::iterator it = func.find(form_name);
	if (it != func.end())
	{
		std::cout << "Intern creates " << form_name << std::endl;
		return func[form_name](target);
	}
	std::cerr << "Error :no such form" << std::endl;
	return (NULL);
}

AForm* createPresidentialPardonForm(std::string target)
{
	AForm *form = new PresidentialPardonForm(target);
	return (form);
}

AForm* createRobotomyRequestForm(std::string target)
{
	AForm *form = new RobotomyRequestForm(target);
	return (form);
}

AForm* createShrubberyCreationForm(std::string target)
{
	AForm *form = new ShrubberyCreationForm(target);
	return (form);
}
