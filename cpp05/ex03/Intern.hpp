#ifndef INTERN_HPP
 #define INTERN_HPP

 #include "RobotomyRequestForm.hpp"
 #include "PresidentialPardonForm.hpp"
 #include "ShrubberyCreationForm.hpp"
 #include <string>
 #include <iostream>
 #include <map>

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();
		AForm *makeForm(std::string name, std::string target);
	private:
		typedef AForm* (*_formFunc)(std::string);
};

	AForm* createPresidentialPardonForm(std::string target);
	AForm* createRobotomyRequestForm(std::string target);
	AForm* createShrubberyCreationForm(std::string target);

#endif
