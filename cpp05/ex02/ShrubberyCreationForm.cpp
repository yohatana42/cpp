#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :_name("SCF"), _const_to_sign(145),_const_to_exec(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :_name("SCF"), _const_to_sign(145),_const_to_exec(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :_name("SCF"), _const_to_sign(145),_const_to_exec(137) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{

}
