#ifndef SCF_HPP
 #define SCF_HPP

 #include "AForm.hpp"
 #include <fstream>

 class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
	private :
		// const std::string _name;
		// bool _is_signed;
		// const int _const_to_sign;
		// const int _const_to_exec;
		std::string _target;
};


#endif
