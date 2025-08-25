#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

 #include <string>
 #include <iostream>
 #include <exception>
 #include <sstream>

class Bureaucrat
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
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();
		std::string getName() const;
		unsigned int getGrade() const;
		std::string print() const;
		void add_grade();
		void remove_grade();
	private:
		Bureaucrat();
		const std::string _name;
		unsigned int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
