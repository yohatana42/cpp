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
		bool execute(Bureaucrat const & executor) const;
	private :
		std::string _target;
};

#endif
