#ifndef FORM_HPP
 #define FORM_HPP

 #include <string>
 #include <iostream>

class Form
{
	class GradeTooHighException : public std::exception
	{

	};

	class GradeTooLowException : public std::exception
	{

	};

	public:

	private:
		const std::string _name;
		bool is_signed;
		const bool to_sign;
		const bool to_exec;
};

#endif
