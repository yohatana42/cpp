#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :_name("SCF"), _const_to_sign(145),_const_to_exec(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :AForm("SCF", 137, 145), _name("SCF"), _const_to_sign(145),_const_to_exec(137)
{
	_is_signed = false;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm("SCF", 137, 145),_name("SCF"), _const_to_sign(145),_const_to_exec(137)
{
	_is_signed = false;
	_target = src._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	_is_signed = false;
	_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	(void)executor;
	(void)_const_to_sign;
	(void)_const_to_exec;
	if (_is_signed)
	{
		std::ofstream strm;
		std::string filename;

		filename = _target + "_shrubbery";
		strm.open(filename.c_str());
		strm << "trees!" << std::endl;
		strm.close();
	}
	else
		std::cerr << _name << " is NOT signed" << std::endl;
}
