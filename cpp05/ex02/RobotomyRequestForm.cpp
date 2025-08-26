#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :_name("RRF"), _const_to_sign(72),_const_to_exec(45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RRF", 45, 72), _name("RRF"), _const_to_sign(72),_const_to_exec(45)
{
	_is_signed = false;
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :AForm("RRF", 45, 72), _name("RRF"), _const_to_sign(72),_const_to_exec(45)
{
	_is_signed = false;
	_target = src._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	_is_signed = false;
	_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	(void)_const_to_sign;
	(void)_const_to_exec;
	std::cout << "execute is sign" << _is_signed << std::endl;
	if (_is_signed)
		std::cout << "rat tat tat" << std::endl;
	else
		std::cerr << _name << " is NOT signed" << std::endl;
}
