#include "Form.hpp"
 #include "Bureaucrat.hpp"

Form::Form() : _name("noname"), _const_to_sign(10), _const_to_exec(10)
{
	_is_signed = false;
}

Form::Form(std::string name, const int exec, const int sign) : _name(name), _const_to_sign(sign), _const_to_exec(exec)
{
	_is_signed = false;
}

Form::Form(const Form& src) :  _name(src.getName()),_const_to_sign(src.getConstToSign()), _const_to_exec(src.getConstToExec())
{
	_is_signed = false;
}

Form& Form::operator=(const Form& src)
{
	this->_is_signed = src.getIsSigned();
	return (*this);
}

Form::~Form() {}

bool Form::beSigned(Bureaucrat& bur)
{
	if (_const_to_sign >= (int)bur.getGrade())
	{
		_is_signed = true;
		return (true);
	}
	else
		throw GradeTooLowException();
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_is_signed);
}

int Form::getConstToSign() const
{
	return (_const_to_sign);
}

int Form::getConstToExec() const
{
	return (_const_to_exec);
}

std::string Form::print_info() const
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

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.print_info();
	return (os);
}
