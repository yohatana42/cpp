#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :_name("RRF"), _const_to_sign(72),_const_to_exec(45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):_name("RRF"), _const_to_sign(72),_const_to_exec(45)
{
	std::cout << target << "" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :_name("RRF"), _const_to_sign(72),_const_to_exec(45) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

}
