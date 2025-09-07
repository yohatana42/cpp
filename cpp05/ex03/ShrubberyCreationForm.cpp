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

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if ((unsigned int)getConstToExec() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (!getIsSigned())
	{
		throw std::runtime_error("is NOT signed");
	}

	std::ofstream strm;
	std::string filename;

	filename = _target + "_shrubbery";
	strm.open(filename.c_str());
	strm << "  /\\ " << std::endl;
	strm << " /  \\" << std::endl;
	strm << "/    \\" << std::endl;
	strm << "  ||  " << std::endl;
	strm.close();
	return (true);
}
