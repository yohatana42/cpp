#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (150 < grade)
		{
			throw GradeTooLowException();
		}
		_grade = grade;
	}
	catch (const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
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

void Bureaucrat::add_grade()
{
	try
	{
		if (_grade + 1 < 1)
			throw GradeTooHighException();
		if (150 < _grade + 1)
		{
			throw GradeTooLowException();
		}
		_grade++;
	}
	catch (const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::remove_grade()
{
	try
	{
		if (_grade - 1 < 1)
			throw GradeTooHighException();
		if (150 < _grade - 1)
		{
			throw GradeTooLowException();
		}
		_grade--;
	}
	catch (const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		if (form.beSigned(*this))
			std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign "
					<< form.getName() << " because "
					<< e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{

	if (form.execute(*this))
		std::cout << _name << " executed " << form.getName() << std::endl;
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
