#ifndef PPF_HPP
 #define PPF_HPP


#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();
		void execute(const Bureaucrat& executor) const;
	private :
		const std::string _name;
		bool _is_signed;
		const int _const_to_sign;
		const int _const_to_exec;
		std::string _target;
};

#endif
