#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "==== error ====" << std::endl;
	try
	{
		Bureaucrat bur2("c", 42);
		std::cout << bur2 << std::endl;
		Form form("form1", 10 ,20);
		std::cout << form << std::endl;
		bur2.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "==== normal ====" << std::endl;
	try
	{
		Form form2("form2", 10 ,20);
		std::cout << form2 << std::endl;
		Bureaucrat bur3("d", 9);
		std::cout << bur3 << std::endl;
		bur3.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
