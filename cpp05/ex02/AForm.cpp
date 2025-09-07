#include "AForm.hpp"
 #include "Bureaucrat.hpp"

AForm::AForm() : _name("noname"), _const_to_sign(10), _const_to_exec(10)
{
	_is_signed = false;
}

AForm::AForm(std::string name, const int exec, const int sign) : _name(name), _const_to_sign(sign), _const_to_exec(exec)
{
	_is_signed = false;
}

AForm::AForm(const AForm& src) :  _name(src.getName()),_const_to_sign(src.getConstToSign()), _const_to_exec(src.getConstToExec())
{
	_is_signed = src.getIsSigned();
}

AForm& AForm::operator=(const AForm& src)
{
	_is_signed = src.getIsSigned();
	return (*this);
}

AForm::~AForm() {}

bool AForm::beSigned(Bureaucrat& bur)
{
	if (_const_to_sign >= (int)bur.getGrade())
	{
		_is_signed = true;
		return (true);
	}
	else
		throw GradeTooLowException();
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_is_signed);
}

int AForm::getConstToSign() const
{
	return (_const_to_sign);
}

int AForm::getConstToExec() const
{
	return (_const_to_exec);
}

std::string AForm::print_info() const
{
	std::stringstream ss;

	ss << "name:" + _name + " const_to_exec:";
	ss << _const_to_exec;
	ss << " const_to_sign:";
	ss << _const_to_sign;
	ss << " is_signed:";
	ss << _is_signed;
	return (ss.str());
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << AForm.print_info();
	return (os);
}
