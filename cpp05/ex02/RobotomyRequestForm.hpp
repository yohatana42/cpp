#ifndef RRF_HPP
 #define RRF_HPP

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
	private :
		const std::string _name;
		bool _is_signed;
		const int _const_to_sign;
		const int _const_to_exec;
		std::string _target;
};

#endif
