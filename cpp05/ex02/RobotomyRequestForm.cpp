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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	if (getIsSigned())
		std::cout << "rat tat tat" << std::endl;
	else
		std::cerr << getName() << " is NOT signed" << std::endl;
}
