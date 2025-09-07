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

// STL(map)は禁止されています
AForm *Intern::makeForm(std::string form_name, std::string target)
{
	_formFunc func[3] = {&createPresidentialPardonForm
					, &createRobotomyRequestForm
					, &createShrubberyCreationForm};
	std::string form_names[3] = {"presidential pardon"
								, "robotomy request"
								, "shrubbery creation"};

	int num = -1;
	for (int i = 0; i < 3; i++)
	{
		if (form_name == form_names[i])
		{
			num = i;
			break ;
		}
	}
	switch (num)
	{
		case 0:
				return func[0](target);
		case 1:
				return func[1](target);
		case 2:
				return func[2](target);
		default:
			std::cerr << "Error :no such form" << std::endl;
			return (NULL);
	}
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
