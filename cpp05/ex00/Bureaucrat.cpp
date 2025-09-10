#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (150 < grade)
	{
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name)
{
	_grade = src.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	_grade = src.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return _name;
}

unsigned int Bureaucrat::getGrade() const
{
	return _grade;
}

// これ逆！！！！
void Bureaucrat::increment()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	if (150 < _grade - 1)
	{
		throw GradeTooLowException();
	}
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade + 1 < 1)
		throw GradeTooHighException();
	if (150 < _grade + 1)
	{
		throw GradeTooLowException();
	}
	_grade++;
}

std::string Bureaucrat::print() const
{
	std::stringstream ss;
	std::string str;
	ss << str << _grade;
	return (_name + ", bureaucrat grade " + ss.str());
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.print();
	return (os);
}
