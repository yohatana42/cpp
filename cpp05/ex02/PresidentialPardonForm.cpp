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
	if ((unsigned int)getConstToExec() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (!getIsSigned())
	{
		throw std::runtime_error("is NOT signed");
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (true);
}
