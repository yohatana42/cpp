#ifndef FORM_HPP
 #define FORM_HPP

 #include <string>
 #include <iostream>
 #include "Bureaucrat.hpp"

class Form
{
	class GradeTooHighException : public std::exception
	{

	};

	class GradeTooLowException : public std::exception
	{

	};

	public:
		Form();
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();
		void beSigned(Bureaucrat bur);


	private:
		const std::string _name;
		bool _is_signed;
		const int _to_sign;
		const int _to_exec;
};

std::ostream& operator<<(std::ostream os, const Form& form);

#endif
