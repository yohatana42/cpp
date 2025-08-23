#include "Form.hpp"

Form::Form() : _to_exec(10), _to_sign(10)
{
	// _to_exec = 10;
	// _to_sign = 10;
}

Form::Form(const Form& src) : _to_exec(10), _to_sign(10) {}

Form& Form::operator=(const Form& src)
{

}

Form::~Form() {}

void Form::beSigned(Bureaucrat bur)
{

}
