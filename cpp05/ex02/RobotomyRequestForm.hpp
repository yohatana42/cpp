#ifndef RRF_HPP
 #define RRF_HPP

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class AForm;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();
		bool execute(Bureaucrat const & executor) const;
	private :
		std::string _target;
};

#endif
