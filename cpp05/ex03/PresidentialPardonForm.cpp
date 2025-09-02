#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 5, 25),_target("")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 5, 25),
																	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :AForm("PPF", 5, 25)
{
	_target = src._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	if (getIsSigned())
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		return (true);
	}
	std::cerr << getName() << " is NOT signed" << std::endl;
	return (false);
}
