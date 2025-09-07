#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :AForm("RRF", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RRF", 45, 72)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :AForm("RRF", 45, 72)
{
	_target = src._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if ((unsigned int)getConstToExec() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (!getIsSigned())
	{
		throw std::runtime_error("is NOT signed");
	}
	std::cout << "rat tat tat" << std::endl;
		return (true);
}
