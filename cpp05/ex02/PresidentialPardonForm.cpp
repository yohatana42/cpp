#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _name("PPF"),
_is_signed(false),
												_const_to_sign(25),
												_const_to_exec(5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 5, 25),_name("PPF"),
_is_signed(false),
																	_const_to_sign(25),
																	_const_to_exec(5),
																	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :AForm("PPF", 5, 25),
_name("PPF"),
																					_is_signed(false),
																					_const_to_sign(25),
																					_const_to_exec(5)
{
	_target = src._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	(void)_const_to_sign;
	(void)_const_to_exec;
	if (_is_signed)
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		std::cerr << _name << " is NOT signed" << std::endl;
}
