#ifndef RRF_HPP
 #define RRF_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();
		void execute(const Bureaucrat& executor) const;
	private :
		const std::string _name;
		bool _is_signed;
		const int _const_to_sign;
		const int _const_to_exec;

};

#endif
