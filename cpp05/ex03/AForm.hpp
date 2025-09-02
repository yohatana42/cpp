#ifndef FORM_HPP
 #define FORM_HPP

 #include <string>
 #include <iostream>
 #include <sstream>
 #include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		AForm();
		AForm(std::string name, const int exec, const int sign);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm();
		bool beSigned(Bureaucrat& bur);
		std::string print_info() const;
		std::string getName() const;
		bool getIsSigned() const;
		int getConstToSign() const;
		int getConstToExec() const;
		virtual bool execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string _name;
		bool _is_signed;
		const int _const_to_sign;
		const int _const_to_exec;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
