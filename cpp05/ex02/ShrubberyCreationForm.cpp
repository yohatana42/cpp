#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :AForm("SCF", 137, 145) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :AForm("SCF", 137, 145)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm("SCF", 137, 145)
{
	_target = src._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned())
	{
		std::ofstream strm;
		std::string filename;

		filename = _target + "_shrubbery";
		strm.open(filename.c_str());
		strm << "trees!" << std::endl;
		strm.close();
	}
	else
		std::cerr << getName() << " is NOT signed" << std::endl;
	(void)executor;
}
