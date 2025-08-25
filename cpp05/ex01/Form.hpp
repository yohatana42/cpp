#ifndef FORM_HPP
 #define FORM_HPP

 #include <string>
 #include <iostream>
 #include <sstream>
 #include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("grade too high");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("grade too low");
			}
	};

	public:
		Form();
		Form(std::string name, const int exec, const int sign);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();
		bool beSigned(Bureaucrat& bur);
		std::string print_info() const;
		std::string getName() const;
		bool getIsSigned() const;
		int getConstToSign() const;
		int getConstToExec() const;

	private:
		const std::string _name;
		bool _is_signed;
		const int _const_to_sign;
		const int _const_to_exec;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
