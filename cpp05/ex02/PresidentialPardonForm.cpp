#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _name("PPF"), _const_to_sign(25),_const_to_exec(5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _name("PPF"), _const_to_sign(25),_const_to_exec(5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : _name("PPF"),
																					_const_to_sign(25),
																					_const_to_exec(5) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{

}
